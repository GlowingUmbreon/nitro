#include "nitro/gx/gx_bank.h"
#include "nitro/gx/gx_init.h"
#include "nitro/gx/gx_state.h"
#include "nitro/os.h"
#include "nitro/reg.h"

static void GX_VRAMCNT_SetLCDC_(u32 lcdc) {
    if ((lcdc & 0x1) != 0) {
        REG_VRAM_CNT_A = 0x80;
    }
    if ((lcdc & 0x2) != 0) {
        REG_VRAM_CNT_B = 0x80;
    }
    if ((lcdc & 0x4) != 0) {
        REG_VRAM_CNT_C = 0x80;
    }
    if ((lcdc & 0x8) != 0) {
        REG_VRAM_CNT_D = 0x80;
    }
    if ((lcdc & 0x10) != 0) {
        REG_VRAM_CNT_E = 0x80;
    }
    if ((lcdc & 0x20) != 0) {
        REG_VRAM_CNT_F = 0x80;
    }
    if ((lcdc & 0x40) != 0) {
        REG_VRAM_CNT_G = 0x80;
    }
    if ((lcdc & 0x80) != 0) {
        REG_VRAM_CNT_H = 0x80;
    }
    if ((lcdc & 0x100) != 0) {
        REG_VRAM_CNT_I = 0x80;
    }
}

void GX_SetBankForBG(s32 bank) {
    GX_banks.lcdc = ~bank & (GX_banks.lcdc | GX_banks.bg);
    GX_banks.bg   = bank;
    switch (bank) {
        case 0x0:
            break;
        case 0x8:
            REG_VRAM_CNT_D = 0x81;
            break;
        case 0xc:
            REG_VRAM_CNT_D = 0x89;
        case 0x4:
            REG_VRAM_CNT_C = 0x81;
            break;
        case 0xe:
            REG_VRAM_CNT_D = 0x91;
        case 0x6:
            REG_VRAM_CNT_C = 0x89;
        case 0x2:
            REG_VRAM_CNT_B = 0x81;
            break;
        case 0xf:
            REG_VRAM_CNT_D = 0x99;
        case 0x7:
            REG_VRAM_CNT_C = 0x91;
        case 0x3:
            REG_VRAM_CNT_B = 0x89;
        case 0x1:
            REG_VRAM_CNT_A = 0x81;
            break;
        case 0xb:
            REG_VRAM_CNT_A = 0x81;
            REG_VRAM_CNT_B = 0x89;
            REG_VRAM_CNT_D = 0x91;
            break;
        case 0xd:
            REG_VRAM_CNT_D = 0x91;
        case 0x5:
            REG_VRAM_CNT_A = 0x81;
            REG_VRAM_CNT_C = 0x89;
            break;
        case 0x9:
            REG_VRAM_CNT_A = 0x81;
            REG_VRAM_CNT_D = 0x89;
            break;
        case 0xa:
            REG_VRAM_CNT_B = 0x81;
            REG_VRAM_CNT_D = 0x89;
            break;
        case 0x70:
            REG_VRAM_CNT_G = 0x99;
        case 0x30:
            REG_VRAM_CNT_F = 0x91;
        case 0x10:
            REG_VRAM_CNT_E = 0x81;
            break;
        case 0x50:
            REG_VRAM_CNT_G = 0x91;
            REG_VRAM_CNT_E = 0x81;
            break;
        case 0x60:
            REG_VRAM_CNT_G = 0x89;
        case 0x20:
            REG_VRAM_CNT_F = 0x81;
            break;
        case 0x40:
            REG_VRAM_CNT_G = 0x81;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

void GX_SetBankForOBJ(s32 bank) {
    GX_banks.lcdc = ~bank & (GX_banks.lcdc | GX_banks.obj);
    GX_banks.obj  = bank;
    switch (bank) {
        case 0x0:
            break;
        case 0x3:
            REG_VRAM_CNT_B = 0x8a;
        case 0x1:
            REG_VRAM_CNT_A = 0x82;
            break;
        case 0x2:
            REG_VRAM_CNT_B = 0x82;
            break;
        case 0x70:
            REG_VRAM_CNT_G = 0x9a;
        case 0x30:
            REG_VRAM_CNT_F = 0x92;
        case 0x10:
            REG_VRAM_CNT_E = 0x82;
            break;
        case 0x50:
            REG_VRAM_CNT_G = 0x92;
            REG_VRAM_CNT_E = 0x82;
            break;
        case 0x60:
            REG_VRAM_CNT_G = 0x8a;
        case 0x20:
            REG_VRAM_CNT_F = 0x82;
            break;
        case 0x40:
            REG_VRAM_CNT_G = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

void GX_SetBankForBGExtPltt(s32 bank) {
    GX_banks.lcdc      = ~bank & (GX_banks.lcdc | GX_banks.bgExtPltt);
    GX_banks.bgExtPltt = bank;
    switch (bank) {
        case 0x10:
            REG_DISPCNT |= 0x40000000;
            REG_VRAM_CNT_E = 0x84;
            break;
        case 0x40:
            REG_DISPCNT |= 0x40000000;
            REG_VRAM_CNT_G = 0x8c;
            break;
        case 0x60:
            REG_VRAM_CNT_G = 0x8c;
        case 0x20:
            REG_VRAM_CNT_F = 0x84;
            REG_DISPCNT |= 0x40000000;
            break;
        case 0x0:
            REG_DISPCNT &= ~0x40000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

BOOL GX_TrySetBankForBGExtPltt(s32 bank) {
    if (!OS_func_0109(bank, GX_lockId)) {
        return false;
    }
    GX_banks.lcdc      = ~bank & (GX_banks.lcdc | GX_banks.bgExtPltt);
    GX_banks.bgExtPltt = bank;
    switch (bank) {
        case 0x10:
            REG_DISPCNT |= 0x40000000;
            REG_VRAM_CNT_E = 0x84;
            break;
        case 0x40:
            REG_DISPCNT |= 0x40000000;
            REG_VRAM_CNT_G = 0x8c;
            break;
        case 0x60:
            REG_VRAM_CNT_G = 0x8c;
        case 0x20:
            REG_VRAM_CNT_F = 0x84;
            REG_DISPCNT |= 0x40000000;
            break;
        case 0x0:
            REG_DISPCNT &= ~0x40000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
    return true;
}

void GX_SetBankForOBJExtPltt(s32 bank) {
    GX_banks.lcdc       = ~bank & (GX_banks.lcdc | GX_banks.objExtPltt);
    GX_banks.objExtPltt = bank;
    switch (bank) {
        case 0x20:
            REG_DISPCNT |= 0x80000000;
            REG_VRAM_CNT_F = 0x85;
            break;
        case 0x40:
            REG_DISPCNT |= 0x80000000;
            REG_VRAM_CNT_G = 0x85;
            break;
        case 0x0:
            REG_DISPCNT &= ~0x80000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

void GX_SetBankForTex(s32 bank) {
    GX_banks.lcdc = (GX_banks.lcdc | GX_banks.tex) & ~bank;
    GX_banks.tex  = bank;
    if (bank == 0) {
        REG_DISP3DCNT &= 0xCFFE;
    } else {
        REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 0x1;
        switch (bank) {
            case 5:
                REG_VRAM_CNT_A = 0x83;
                REG_VRAM_CNT_C = 0x8B;
                break;
            case 9:
                REG_VRAM_CNT_A = 0x83;
                REG_VRAM_CNT_D = 0x8B;
                break;
            case 10:
                REG_VRAM_CNT_B = 0x83;
                REG_VRAM_CNT_D = 0x8B;
                break;
            case 11:
                REG_VRAM_CNT_A = 0x83;
                REG_VRAM_CNT_B = 0x8B;
                REG_VRAM_CNT_D = 0x93;
                break;
            case 13:
                REG_VRAM_CNT_A = 0x83;
                REG_VRAM_CNT_C = 0x8B;
                REG_VRAM_CNT_D = 0x93;
                break;
            case 8:
                REG_VRAM_CNT_D = 0x83;
                break;
            case 12:
                REG_VRAM_CNT_D = 0x8B;
            case 4:
                REG_VRAM_CNT_C = 0x83;
                break;
            case 14:
                REG_VRAM_CNT_D = 0x93;
            case 6:
                REG_VRAM_CNT_C = 0x8B;
            case 2:
                REG_VRAM_CNT_B = 0x83;
                break;
            case 15:
                REG_VRAM_CNT_D = 0x9B;
            case 7:
                REG_VRAM_CNT_C = 0x93;
            case 3:
                REG_VRAM_CNT_B = 0x8B;
            case 1:
                REG_VRAM_CNT_A = 0x83;
                break;
        }
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

void GX_SetBankForTexPltt(s32 bank) {
    GX_banks.lcdc    = (GX_banks.lcdc | GX_banks.texPltt) & ~bank;
    GX_banks.texPltt = bank;
    switch (bank) {
        case 0x60:
            REG_VRAM_CNT_G = 0x8B;
        case 0x20:
            REG_VRAM_CNT_F = 0x83;
            break;
        case 0x40:
            REG_VRAM_CNT_G = 0x83;
            break;
        case 0x70:
            REG_VRAM_CNT_G = 0x9B;
        case 0x30:
            REG_VRAM_CNT_F = 0x93;
        case 0x10:
            REG_VRAM_CNT_E = 0x83;
            break;
        case 0x0:
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

void GX_SetBankForClearImage(s32 bank) {
    GX_banks.lcdc       = (GX_banks.lcdc | GX_banks.clearImage) & ~bank;
    GX_banks.clearImage = bank;
    switch (bank) {
        case 3:
            REG_VRAM_CNT_A = 0x93;
        case 2:
            REG_VRAM_CNT_B = 0x9B;
            REG_DISP3DCNT |= 0x4000;
            break;
        case 12:
            REG_VRAM_CNT_C = 0x93;
        case 8:
            REG_VRAM_CNT_D = 0x9B;
            REG_DISP3DCNT |= 0x4000;
            break;
        case 0:
            REG_DISP3DCNT &= ~0x4000;
            break;
        case 1:
            REG_VRAM_CNT_A = 0x9B;
            REG_DISP3DCNT |= 0x4000;
            break;
        case 4:
            REG_VRAM_CNT_C = 0x9B;
            REG_DISP3DCNT |= 0x4000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

// https://decomp.me/scratch/FVqpo
void GX_SetBankForARM7(s32 bank) {
    GX_banks.lcdc = (GX_banks.lcdc | GX_banks.arm7) & ~bank;
    GX_banks.arm7 = bank;
    switch (bank) {
        case 0:
            break;
        case 12:
            REG_VRAM_CNT_D = 0x8A;
            REG_VRAM_CNT_C = 0x82;
            break;
        case 4:
            REG_VRAM_CNT_C = 0x82;
            break;
        case 8:
            REG_VRAM_CNT_D = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

BOOL GX_TrySetBankForOBJExtPltt(s32 bank) {
    if (!OS_func_0109(bank, GX_lockId)) {
        return false;
    }
    GX_banks.lcdc       = ~bank & (GX_banks.lcdc | GX_banks.objExtPltt);
    GX_banks.objExtPltt = bank;
    switch (bank) {
        case 0x20:
            REG_DISPCNT |= 0x80000000;
            REG_VRAM_CNT_F = 0x85;
            break;
        case 0x40:
            REG_DISPCNT |= 0x80000000;
            REG_VRAM_CNT_G = 0x85;
            break;
        case 0x0:
            REG_DISPCNT &= ~0x80000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
    return true;
}

void GX_SetBankForLCDC(s32 bank) {
    GX_banks.lcdc |= bank;
    GX_VRAMCNT_SetLCDC_(bank);
}

// https://decomp.me/scratch/7y6E9
void GX_SetBankForSubBG(s32 bank) {
    GX_banks.lcdc  = ~bank & (GX_banks.lcdc | GX_banks.subBg);
    GX_banks.subBg = bank;
    switch (bank) {
        case 0x0:
            break;
        case 0x4:
            REG_VRAM_CNT_C = 0x84;
            break;
        case 0x180:
            REG_VRAM_CNT_I = 0x81;
        case 0x80:
            REG_VRAM_CNT_H = 0x81;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

void GX_SetBankForSubOBJ(s32 bank) {
    GX_banks.lcdc   = ~bank & (GX_banks.lcdc | GX_banks.subObj);
    GX_banks.subObj = bank;
    switch (bank) {
        case 0x0:
            break;
        case 0x8:
            REG_VRAM_CNT_D = 0x84;
            break;
        case 0x100:
            REG_VRAM_CNT_I = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

void GX_SetBankForSubBGExtPltt(s32 bank) {
    GX_banks.lcdc         = ~bank & (GX_banks.lcdc | GX_banks.subBgExtPltt);
    GX_banks.subBgExtPltt = bank;
    switch (bank) {
        case 0x80:
            REG_DISPCNT_SUB |= 0x40000000;
            REG_VRAM_CNT_H = 0x82;
            break;
        case 0x0:
            REG_DISPCNT_SUB &= ~0x40000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

BOOL GX_TrySetBankForSubBGExtPltt(s32 bank) {
    if (!OS_func_0109(bank, GX_lockId)) {
        return false;
    }
    GX_banks.lcdc         = ~bank & (GX_banks.lcdc | GX_banks.subBgExtPltt);
    GX_banks.subBgExtPltt = bank;
    switch (bank) {
        case 0x80:
            REG_DISPCNT_SUB |= 0x40000000;
            REG_VRAM_CNT_H = 0x82;
            break;
        case 0x0:
            REG_DISPCNT_SUB &= ~0x40000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
    return true;
}

void GX_SetBankForSubOBJExtPltt(s32 bank) {
    GX_banks.lcdc          = ~bank & (GX_banks.lcdc | GX_banks.subObjExtPltt);
    GX_banks.subObjExtPltt = bank;
    switch (bank) {
        case 0x100:
            REG_DISPCNT_SUB |= 0x80000000;
            REG_VRAM_CNT_I = 0x83;
            break;
        case 0x0:
            REG_DISPCNT_SUB &= ~0x80000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
}

BOOL GX_TrySetBankForSubOBJExtPltt(s32 bank) {
    if (!OS_func_0109(bank, GX_lockId)) {
        return false;
    }
    GX_banks.lcdc          = ~bank & (GX_banks.lcdc | GX_banks.subObjExtPltt);
    GX_banks.subObjExtPltt = bank;
    switch (bank) {
        case 0x100:
            REG_DISPCNT_SUB |= 0x80000000;
            REG_VRAM_CNT_I = 0x83;
            break;
        case 0x0:
            REG_DISPCNT_SUB &= ~0x80000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(GX_banks.lcdc);
    return true;
}

static u16 resetBankForX_(u16 *bank) {
    u16 prev = *bank;
    *bank    = 0;
    GX_banks.lcdc |= prev;
    GX_VRAMCNT_SetLCDC_(prev);
    return prev;
}

u16 GX_ResetBankForTex(void) {
    return resetBankForX_(&GX_banks.tex);
}

u16 GX_ResetBankForTexPltt(void) {
    return resetBankForX_(&GX_banks.texPltt);
}

u16 GX_ResetBankForSubOBJ(void) {
    return resetBankForX_(&GX_banks.subObj);
}

u16 GX_ResetBankForBGExtPltt(void) {
    REG_DISPCNT &= ~0x40000000;
    return resetBankForX_(&GX_banks.bgExtPltt);
}

u16 GX_ResetBankForOBJExtPltt(void) {
    REG_DISPCNT &= ~0x80000000;
    return resetBankForX_(&GX_banks.objExtPltt);
}

u16 GX_ResetBankForSubBGExtPltt(void) {
    REG_DISPCNT_SUB &= ~0x40000000;
    return resetBankForX_(&GX_banks.subBgExtPltt);
}

u16 GX_ResetBankForSubOBJExtPltt(void) {
    REG_DISPCNT_SUB &= ~0x80000000;
    return resetBankForX_(&GX_banks.subObjExtPltt);
}

static u16 disableBankForX_(u16 *bank) {
    u16 prev = *bank;
    *bank    = 0;
    if ((prev & 0x1) != 0) {
        REG_VRAM_CNT_A = 0;
    }
    if ((prev & 0x2) != 0) {
        REG_VRAM_CNT_B = 0;
    }
    if ((prev & 0x4) != 0) {
        REG_VRAM_CNT_C = 0;
    }
    if ((prev & 0x8) != 0) {
        REG_VRAM_CNT_D = 0;
    }
    if ((prev & 0x10) != 0) {
        REG_VRAM_CNT_E = 0;
    }
    if ((prev & 0x20) != 0) {
        REG_VRAM_CNT_F = 0;
    }
    if ((prev & 0x40) != 0) {
        REG_VRAM_CNT_G = 0;
    }
    if ((prev & 0x80) != 0) {
        REG_VRAM_CNT_H = 0;
    }
    if ((prev & 0x100) != 0) {
        REG_VRAM_CNT_I = 0;
    }
    OSi_UnlockVram((u32) prev, GX_lockId);
    return prev;
}

u16 GX_DisableBankForBG(void) {
    return disableBankForX_(&GX_banks.bg);
}

u16 GX_DisableBankForOBJ(void) {
    return disableBankForX_(&GX_banks.obj);
}

u16 GX_DisableBankForBGExtPltt(void) {
    REG_DISPCNT &= ~0x40000000;
    return disableBankForX_(&GX_banks.bgExtPltt);
}

u16 GX_DisableBankForOBJExtPltt(void) {
    REG_DISPCNT &= ~0x80000000;
    return disableBankForX_(&GX_banks.objExtPltt);
}

u16 GX_DisableBankForTex(void) {
    return disableBankForX_(&GX_banks.tex);
}

u16 GX_DisableBankForTexPltt(void) {
    return disableBankForX_(&GX_banks.texPltt);
}

u16 GX_DisableBankForClearImage(void) {
    return disableBankForX_(&GX_banks.clearImage);
}

u16 GX_DisableBankForARM7(void) {
    return disableBankForX_(&GX_banks.arm7);
}

u16 GX_DisableBankForLCDC(void) {
    return disableBankForX_(&GX_banks.lcdc);
}

u16 GX_DisableBankForSubBG(void) {
    return disableBankForX_(&GX_banks.subBg);
}

u16 GX_DisableBankForSubOBJ(void) {
    return disableBankForX_(&GX_banks.subObj);
}

u16 GX_DisableBankForSubBGExtPltt(void) {
    REG_DISPCNT_SUB &= ~0x40000000;
    return disableBankForX_(&GX_banks.subBgExtPltt);
}

u16 GX_DisableBankForSubOBJExtPltt(void) {
    REG_DISPCNT_SUB &= ~0x80000000;
    return disableBankForX_(&GX_banks.subObjExtPltt);
}
