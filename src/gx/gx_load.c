#include "nitro/gx/gx_load.h"
#include "nitro/gx/gx_bank.h"
#include "nitro/gx/gx_bg.h"
#include "nitro/gx/gx_init.h"
#include "nitro/gx/gx_obj.h"
#include "nitro/hw.h"
#include "nitro/mi.h"

typedef struct GX_UnkStruct3 {
    /* 00 */ u32 unk_00;
    /* 04 */ void *unk_04;
    /* 08 */ u32 unk_08;
    /* 0c */ u32 unk_0c;
    /* 10 */ void *unk_10;
    /* 14 */ s32 unk_14;
    /* 18 */ u32 unk_18;
    /* 1c */
} GX_UnkStruct3;

static GX_UnkStruct3 data_0216a0fc;

inline void GX_LoadVram16(void *src, void *dst, u32 size) {
    if (GX_defaultDma != -1 && size > 28) {
        MI_DmaCopy16(GX_defaultDma, src, dst, size);
    } else {
        MIi_CpuCopy16(src, dst, size);
    }
}

inline void GX_LoadVram32(void *src, void *dst, u32 size) {
    if (GX_defaultDma != -1 && size > 48) {
        MI_DmaCopy32(GX_defaultDma, src, dst, size);
    } else {
        MIi_CpuCopy32(src, dst, size);
    }
}

void GX_LoadBGPltt(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, HW_PLTT + offset, size);
}

void GXS_LoadBGPltt(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, HW_DB_PLTT + offset, size);
}

void GX_LoadOBJPltt(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, HW_PLTT + offset + 0x200, size);
}

void GXS_LoadOBJPltt(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, HW_DB_PLTT + offset + 0x200, size);
}

void GX_LoadOAM(GXOamAttr *oam, u32 offset, u32 size) {
    GX_LoadVram32(oam, HW_OAM + offset, size);
}

void GXS_LoadOAM(GXOamAttr *oam, u32 offset, u32 size) {
    GX_LoadVram32(oam, HW_DB_OAM + offset, size);
}

// https://decomp.me/scratch/c5fLJ
void GX_LoadOBJ(void *ptr, u32 offset, u32 size) {
    GX_LoadVram32(ptr, HW_OBJ_VRAM + offset, size);
}

// https://decomp.me/scratch/es3pz
void GXS_LoadOBJ(void *ptr, u32 offset, u32 size) {
    GX_LoadVram32(ptr, HW_DB_OBJ_VRAM + offset, size);
}

void GX_LoadBG0Scr(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, G2_GetBG0ScrPtr() + offset, size);
}

void GXS_LoadBG0Scr(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, G2S_GetBG0ScrPtr() + offset, size);
}

void GX_LoadBG1Scr(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, G2_GetBG1ScrPtr() + offset, size);
}

void GXS_LoadBG1Scr(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, G2S_GetBG1ScrPtr() + offset, size);
}

void GX_LoadBG2Scr(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, G2_GetBG2ScrPtr() + offset, size);
}

void GXS_LoadBG2Bmp(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, G2S_GetBG2ScrPtr() + offset, size);
}

void GX_LoadBG3Scr(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, G2_GetBG3ScrPtr() + offset, size);
}

void GXS_LoadBG3Bmp(void *ptr, u32 offset, u32 size) {
    GX_LoadVram16(ptr, G2S_GetBG3ScrPtr() + offset, size);
}

void GX_LoadBG0Char(void *ptr, u32 offset, u32 size) {
    GX_LoadVram32(ptr, G2_GetBG0CharPtr() + offset, size);
}

void GXS_LoadBG0Char(void *ptr, u32 offset, u32 size) {
    GX_LoadVram32(ptr, G2S_GetBG0CharPtr() + offset, size);
}

void GX_LoadBG1Char(void *ptr, u32 offset, u32 size) {
    GX_LoadVram32(ptr, G2_GetBG1CharPtr() + offset, size);
}

void GXS_LoadBG1Char(void *ptr, u32 offset, u32 size) {
    GX_LoadVram32(ptr, G2S_GetBG1CharPtr() + offset, size);
}

void GX_LoadBG2Char(void *ptr, u32 offset, u32 size) {
    GX_LoadVram32(ptr, G2_GetBG2CharPtr() + offset, size);
}

void GXS_LoadBG2Char(void *ptr, u32 offset, u32 size) {
    GX_LoadVram32(ptr, G2S_func_0005() + offset, size);
}

void GX_LoadBG3Char(void *ptr, u32 offset, u32 size) {
    GX_LoadVram32(ptr, G2_GetBG3CharPtr() + offset, size);
}

void GXS_LoadBG3Char(void *ptr, u32 offset, u32 size) {
    GX_LoadVram32(ptr, G2S_func_0006() + offset, size);
}

void GX_BeginLoadBGExtPltt(void) {
    data_0216a0fc.unk_14 = GX_ResetBankForBGExtPltt();
    switch (data_0216a0fc.unk_14) {
        case 0x0:
            break;
        case 0x10:
            data_0216a0fc.unk_10 = ((void *) 0x06880000);
            data_0216a0fc.unk_0c = 0;
            break;
        case 0x40:
            data_0216a0fc.unk_10 = ((void *) 0x06894000);
            data_0216a0fc.unk_0c = 0x4000;
            break;
        case 0x20:
        case 0x60:
            data_0216a0fc.unk_10 = ((void *) 0x06890000);
            data_0216a0fc.unk_0c = 0;
            break;
    }
}

void GX_LoadBGExtPltt(void *ptr, u32 offset, u32 size) {
    void *vram = (data_0216a0fc.unk_10 + offset) - data_0216a0fc.unk_0c;
    if (GX_defaultDma != -1) {
        MI_func_0002(GX_defaultDma, ptr, vram, size, 0, 0);
    } else {
        MIi_CpuCopy32(ptr, vram, size);
    }
}

void GX_EndLoadBGExtPltt(void) {
    if (GX_defaultDma != -1) {
        MI_func_0003(GX_defaultDma);
    }
    GX_SetBankForBGExtPltt(data_0216a0fc.unk_14);
    data_0216a0fc.unk_14 = 0;
    data_0216a0fc.unk_10 = 0;
    data_0216a0fc.unk_0c = 0;
}

void GX_BeginLoadOBJExtPltt(void) {
    data_0216a0fc.unk_08 = GX_ResetBankForOBJExtPltt();
    switch (data_0216a0fc.unk_08) {
        case 0x0:
            break;
        case 0x40:
            data_0216a0fc.unk_04 = ((void *) 0x06894000);
            break;
        case 0x20:
            data_0216a0fc.unk_04 = ((void *) 0x06890000);
            break;
    }
}

void GX_LoadOBJExtPltt(void *ptr, u32 offset, u32 size) {
    void *vram = data_0216a0fc.unk_04 + offset;
    if (GX_defaultDma != -1) {
        MI_func_0002(GX_defaultDma, ptr, vram, size, 0, 0);
    } else {
        MIi_CpuCopy32(ptr, vram, size);
    }
}

void GX_EndLoadOBJExtPltt(void) {
    if (GX_defaultDma != -1) {
        MI_func_0003(GX_defaultDma);
    }
    GX_SetBankForOBJExtPltt(data_0216a0fc.unk_08);
    data_0216a0fc.unk_08 = 0;
    data_0216a0fc.unk_04 = 0;
}

void GXS_BeginLoadBGExtPltt(void) {
    data_0216a0fc.unk_00 = GX_ResetBankForSubBGExtPltt();
}

void GXS_LoadBGExtPltt(void *ptr, u32 offset, u32 size) {
    if (GX_defaultDma != -1) {
        MI_func_0002(GX_defaultDma, ptr, ((void *) 0x06898000) + offset, size, 0, 0);
    } else {
        MIi_CpuCopy32(ptr, ((void *) 0x06898000) + offset, size);
    }
}

void GXS_EndLoadBGExtPltt(void) {
    if (GX_defaultDma != -1) {
        MI_func_0003(GX_defaultDma);
    }
    GX_SetBankForSubBGExtPltt(data_0216a0fc.unk_00);
    data_0216a0fc.unk_00 = 0;
}

void GXS_BeginLoadOBJExtPltt(void) {
    data_0216a0fc.unk_18 = GX_ResetBankForSubOBJExtPltt();
}

void GXS_LoadOBJExtPltt(void *ptr, u32 offset, u32 size) {
    if (GX_defaultDma != -1) {
        MI_func_0002(GX_defaultDma, ptr, ((void *) 0x068a0000) + offset, size, 0, 0);
    } else {
        MIi_CpuCopy32(ptr, ((void *) 0x068a0000) + offset, size);
    }
}

void GXS_EndLoadOBJExtPltt(void) {
    if (GX_defaultDma != -1) {
        MI_func_0003(GX_defaultDma);
    }
    GX_SetBankForSubOBJExtPltt(data_0216a0fc.unk_18);
    data_0216a0fc.unk_18 = 0;
}