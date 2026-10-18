#include "nitro/gx/g3.h"
#include "nitro/fx.h"
#include "nitro/gx/gx_fifo.h"
#include "nitro/mi.h"
#include "nitro/reg.h"
#include "nitro/types.h"

static void GXi_NopClearFifo128_(volatile void *arg0);

void G3_LoadMtx44(MtxFx44 *arg0) {
    REG_GFX_FIFO = 0x16;
    GX_SendFifo64B(arg0, (void *) &REG_GFX_FIFO);
}

void G3_LoadMtx43(MtxFx43 *arg0) {
    REG_GFX_FIFO = 0x17;
    GX_SendFifo48B(arg0, (void *) &REG_GFX_FIFO);
}

void G3X_ClearFifo(void) {
    GXi_NopClearFifo128_((void *) &REG_GFX_FIFO);
    while (REG_GFX_STATUS & 0x08000000) {
    }
}

void G3X_InitMtxStack(void) {
    u32 pv;
    u32 pj;

    REG_GFX_STATUS |= 0x8000;
    while (G3X_GetMtxStackLevelPV(&pv) != 0) {
    }
    while (G3X_GetMtxStackLevelPJ(&pj) != 0) {
    }
    REG_GFX_FIFO_MATRIX_MODE     = 3;
    REG_GFX_FIFO_MATRIX_IDENTITY = 0;
    REG_GFX_FIFO_MATRIX_MODE     = 0;
    if (pj != 0) {
        REG_GFX_FIFO_MATRIX_POP = pj;
    }
    REG_GFX_FIFO_MATRIX_IDENTITY = 0;
    REG_GFX_FIFO_MATRIX_MODE     = 2;
    REG_GFX_FIFO_MATRIX_POP      = pv;
    REG_GFX_FIFO_MATRIX_IDENTITY = 0;
}

void G3X_ResetMtxStack(void) {
    u32 pv;
    u32 pj;

    REG_GFX_STATUS |= 0x8000;
    while (G3X_GetMtxStackLevelPV(&pv) != 0) {
    }
    while (G3X_GetMtxStackLevelPJ(&pj) != 0) {
    }
    REG_GFX_FIFO_MATRIX_MODE     = 3;
    REG_GFX_FIFO_MATRIX_IDENTITY = 0;
    REG_GFX_FIFO_MATRIX_MODE     = 0;
    if (pj != 0) {
        REG_GFX_FIFO_MATRIX_POP = pj;
    }
    REG_GFX_FIFO_MATRIX_MODE     = 2;
    REG_GFX_FIFO_MATRIX_POP      = pv;
    REG_GFX_FIFO_MATRIX_IDENTITY = 0;
}

void G3X_SetFog(BOOL arg0, s32 arg1, s32 arg2, s16 offset) {
    if (arg0) {
        REG_GFX_FOG_OFFSET = offset;
        REG_DISP3DCNT      = 0x80 | ((arg2 << 8) | (arg1 << 6)) | (~0x3f40 & REG_DISP3DCNT);
    } else {
        REG_DISP3DCNT = 0xCF7F & REG_DISP3DCNT;
    }
}

void G3X_SetEdgeColorTable(const void *arg0) {
    MIi_CpuCopy16(arg0, (void *) &REG_GFX_EDGE_TABLE, 16);
}

void G3X_SetFogTable(const void *arg0) {
    MI_Copy32B(arg0, (void *) &REG_GFX_FOG_TABLE);
}

void G3X_SetClearColor(u32 rgb, u32 a, u32 depth, u32 param4, BOOL param5) {
    s32 color;

    color = (param4 << 0x18) | (rgb | (a << 16));
    if (param5 != 0) {
        color |= 0x8000;
    }
    REG_GFX_FOG_CLEAR_COLOR = color;
    REG_GFX_FOG_CLEAR_DEPTH = depth;
}

s32 G3X_GetMtxStackLevelPV(u32 *arg0) {
    if (REG_GFX_STATUS & 0x4000) {
        return -1;
    }
    *arg0 = (REG_GFX_STATUS & 0x1F00) >> 8;
    return 0;
}

s32 G3X_GetMtxStackLevelPJ(u32 *arg0) {
    if (REG_GFX_STATUS & 0x4000) {
        return -1;
    }
    *arg0 = (REG_GFX_STATUS & 0x2000) >> 13;
    return 0;
}

THUMB_DISABLE();
#ifdef NITRO_NO_ASM
static void GXi_NopClearFifo128_(volatile void *arg0) {
    s32 i;
    for (i = 0; i < 128; ++i) {
        *(vu32 *) arg0 = 0;
    }
}
#else
static void GXi_NopClearFifo128_(volatile void *arg0) {
    #if __MWERKS__ // clang-format off
    asm {
        mov r1, 0
        mov r2, 0
        mov r3, 0
        mov ip, 0
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
        stmia r0, {r1-r3, ip}
    }
    #endif // clang-format on
}
#endif
THUMB_ENABLE();

void G3i_OrthoW_(fx32 top, fx32 bottom, fx32 left, fx32 right, fx32 near, fx32 far, fx32 scale, BOOL arg7,
                 MtxFx44 *out) {
    MtxFx44 temp;
    MtxFx44 *mtx;

    mtx = out;
    if (mtx == NULL) {
        mtx = &temp;
    }
    MTX_OrthoW(top, bottom, left, right, near, far, scale, mtx);
    if (arg7) {
        REG_GFX_FIFO_MATRIX_MODE = 0;
        G3_LoadMtx44(mtx);
    }
}

void G3_RotZ(u32 sin, u32 cos) {
    REG_GFX_FIFO_MATRIX_MULT_3x3 = cos;
    REG_GFX_FIFO_MATRIX_MULT_3x3 = sin;
    REG_GFX_FIFO_MATRIX_MULT_3x3 = 0;
    REG_GFX_FIFO_MATRIX_MULT_3x3 = -sin;
    REG_GFX_FIFO_MATRIX_MULT_3x3 = cos;
    REG_GFX_FIFO_MATRIX_MULT_3x3 = 0;
    REG_GFX_FIFO_MATRIX_MULT_3x3 = 0;
    REG_GFX_FIFO_MATRIX_MULT_3x3 = 0;
    REG_GFX_FIFO_MATRIX_MULT_3x3 = FX32_ONE;
}
