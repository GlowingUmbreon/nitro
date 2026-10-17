#include "nitro/gx/gx_bg.h"
#include "nitro/hw.h"
#include "nitro/reg.h"

void *G2_GetBG0ScrPtr(void) {
    u32 cnt = (REG_BG0CNT & 0x1f00) >> 8 << 11;
    return ((REG_DISPCNT & 0x38000000) >> 27 << 16) + HW_BG_VRAM + cnt;
}

void *G2S_GetBG0ScrPtr(void) {
    return ((REG_BG0CNT_SUB & 0x1f00) >> 8 << 11) + HW_DB_BG_VRAM;
}

void *G2_GetBG1ScrPtr(void) {
    u32 cnt = ((REG_BG1CNT & 0x1f00) >> 8 << 11);
    return ((REG_DISPCNT & 0x38000000) >> 27 << 16) + HW_BG_VRAM + cnt;
}

void *G2S_GetBG1ScrPtr(void) {
    return ((REG_BG1CNT_SUB & 0x1f00) >> 8 << 11) + HW_DB_BG_VRAM;
}

THUMB_DISABLE();
void *G2_GetBG2ScrPtr(void) {
    u32 uVar1 = REG_DISPCNT & 0x7;
    u32 uVar2 = REG_BG2CNT;
    u32 uVar3 = (REG_DISPCNT & 0x38000000) >> 27 << 16;
    u32 uVar4 = (uVar2 & 0x1f00) >> 8;
    switch (uVar1) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            return uVar3 + HW_BG_VRAM + (uVar4 << 11);
        case 5:
            if ((uVar2 & 0x80) != 0) {
                return (uVar4 << 14) + HW_BG_VRAM;
            } else {
                return uVar3 + HW_BG_VRAM + (uVar4 << 11);
            }
        case 6:
            return HW_BG_VRAM;
        default:
            return 0;
    }
}

void *G2S_GetBG2ScrPtr(void) {
    u32 uVar1 = REG_DISPCNT_SUB & 0x7;
    u32 uVar2 = REG_BG2CNT_SUB;
    u32 uVar3 = (uVar2 & 0x1f00) >> 8;
    switch (uVar1) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            return (uVar3 << 11) + HW_DB_BG_VRAM;
        case 5:
            if ((uVar2 & 0x80) != 0) {
                return (uVar3 << 14) + HW_DB_BG_VRAM;
            } else {
                return (uVar3 << 11) + HW_DB_BG_VRAM;
            }
        case 6:
            return 0;
        default:
            return 0;
    }
}

void *G2_GetBG3ScrPtr(void) {
    u32 uVar1 = REG_DISPCNT & 0x7;
    u32 uVar2 = REG_BG3CNT;
    u32 uVar3 = (REG_DISPCNT & 0x38000000) >> 27 << 16;
    u32 uVar4 = (uVar2 & 0x1f00) >> 8;
    switch (uVar1) {
        case 0:
        case 1:
        case 2:
            return uVar3 + HW_BG_VRAM + (uVar4 << 11);
        case 3:
        case 4:
        case 5:
            if ((uVar2 & 0x80) != 0) {
                return (uVar4 << 14) + HW_BG_VRAM;
            } else {
                return uVar3 + HW_BG_VRAM + (uVar4 << 11);
            }
        case 6:
            return 0;
        default:
            return 0;
    }
}

void *G2S_GetBG3ScrPtr(void) {
    u32 uVar1 = REG_DISPCNT_SUB & 0x7;
    u32 uVar2 = REG_BG3CNT_SUB;
    u32 uVar3 = (uVar2 & 0x1f00) >> 8;
    switch (uVar1) {
        case 0:
        case 1:
        case 2:
            return (uVar3 << 11) + HW_DB_BG_VRAM;
        case 3:
        case 4:
        case 5:
            if ((uVar2 & 0x80) != 0) {
                return (uVar3 << 14) + HW_DB_BG_VRAM;
            } else {
                return (uVar3 << 11) + HW_DB_BG_VRAM;
            }
        case 6:
            return 0;
        default:
            return 0;
    }
}
THUMB_ENABLE();

void *G2_GetBG0CharPtr(void) {
    u32 r1   = (REG_BG0CNT & 0x3c) >> 2 << 14;
    void *r0 = ((REG_DISPCNT & 0x7000000) >> 24 << 16) + HW_BG_VRAM;
    return r0 + r1;
}

void *G2S_GetBG0CharPtr(void) {
    return ((REG_BG0CNT_SUB & 0x3c) >> 2 << 14) + HW_DB_BG_VRAM;
}

void *G2_GetBG1CharPtr(void) {
    u32 r1   = (REG_BG1CNT & 0x3c) >> 2 << 14;
    void *r0 = ((REG_DISPCNT & 0x7000000) >> 24 << 16) + HW_BG_VRAM;
    return r0 + r1;
}

void *G2S_GetBG1CharPtr(void) {
    return ((REG_BG1CNT_SUB & 0x3c) >> 2 << 14) + HW_DB_BG_VRAM;
}

void *G2_GetBG2CharPtr(void) {
    s32 r0 = REG_DISPCNT & 0x7;
    u32 r2 = REG_BG2CNT;
    if (r0 < 5 || (r2 & 0x80) == 0) {
        return ((REG_DISPCNT & 0x7000000) >> 24 << 16) + HW_BG_VRAM + ((u32) (r2 & 0x3c) >> 2 << 14);
    }
    return 0;
}

void *G2S_func_0005(void) {
    s32 r0 = REG_DISPCNT_SUB & 0x7;
    u32 r1 = REG_BG2CNT_SUB;
    if (r0 < 5 || (r1 & 0x80) == 0) {
        return ((r1 & 0x3c) >> 2 << 14) + HW_DB_BG_VRAM;
    }
    return 0;
}

void *G2_GetBG3CharPtr(void) {
    s32 r0 = REG_DISPCNT & 0x7;
    u32 r2 = REG_BG3CNT;
    if (r0 < 3 || (r0 < 6 && (r2 & 0x80) == 0)) {
        return ((REG_DISPCNT & 0x7000000) >> 24 << 16) + HW_BG_VRAM + ((u32) (r2 & 0x3c) >> 2 << 14);
    }
    return 0;
}

void *G2S_func_0006(void) {
    s32 r0 = REG_DISPCNT_SUB & 0x7;
    u32 r1 = REG_BG3CNT_SUB;
    if (r0 < 3 || (r0 < 6 && (r1 & 0x80) == 0)) {
        return ((r1 & 0x3c) >> 2 << 14) + HW_DB_BG_VRAM;
    }
    return 0;
}

THUMB_DISABLE();
void G2x_SetBGyAffine_(u32 *reg, MtxFx22 *mtx, s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 x;
    s32 y;
    reg[0] = ((u16) (mtx->_00 << 12 >> 16)) | ((u16) (mtx->_01 << 12 >> 16) << 16);
    reg[1] = ((u16) (mtx->_10 << 12 >> 16)) | ((u16) (mtx->_11 << 12 >> 16) << 16);
    x      = ((mtx->_00 * (x1 - x0)) + (mtx->_01 * (y1 - y0)) + (x0 << 12)) >> 4;
    y      = ((mtx->_10 * (x1 - x0)) + (mtx->_11 * (y1 - y0)) + (y0 << 12)) >> 4;
    reg[2] = x;
    reg[3] = y;
}
THUMB_ENABLE();
