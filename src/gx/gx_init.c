#include "nitro/gx/gx_init.h"
#include "nitro/gx/gx_state.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nitro/os/os_irq.h"

u16 GX_data_0004  = 1;
u32 GX_defaultDma = 3;
u16 GX_data_0002  = 0;
u16 GX_lockId     = 0;

void GX_Init(void) {
    REG_POWER_CNT |= 0x8000;
    REG_POWER_CNT = (REG_POWER_CNT & ~0x20e) | 0x20e;
    REG_POWER_CNT |= 0x1;

    GX_InitGXState();

    while (GX_lockId == 0) {
        s32 lock = OS_GetLockID();
        if (lock == OS_LOCK_ID_ERROR) {
            OS_Panic();
        }
        GX_lockId = lock;
    }

    REG_DISPSTAT = 0;
    REG_DISPCNT  = 0;

    if (GX_defaultDma != -1) {
        MI_DmaFill32(GX_defaultDma, &REG_BG0CNT, 0, 0x60);
        REG_MASTER_BRIGHT = 0;
        MI_DmaFill32(GX_defaultDma, &REG_DISPCNT_SUB, 0, 0x70);
    } else {
        MIi_CpuClear32(0, &REG_BG0CNT, 0x60);
        REG_MASTER_BRIGHT = 0;
        MIi_CpuClear32(0, &REG_DISPCNT_SUB, 0x70);
    }

    REG_BG2PA     = 0x100;
    REG_BG2PD     = 0x100;
    REG_BG3PA     = 0x100;
    REG_BG3PD     = 0x100;
    REG_BG2PA_SUB = 0x100;
    REG_BG2PD_SUB = 0x100;
    REG_BG3PA_SUB = 0x100;
    REG_BG3PD_SUB = 0x100;
}

u16 GX_HBlankIntr(BOOL param1) {
    u16 prevStat = REG_DISPSTAT & 0x10;
    if (param1) {
        REG_DISPSTAT |= 0x10;
        return prevStat;
    } else {
        REG_DISPSTAT &= ~0x10;
        return prevStat;
    }
}

u32 GX_VBlankIntr(BOOL param1) {
    u32 prevStat = REG_DISPSTAT & 0x8;
    if (param1) {
        REG_DISPSTAT |= 0x8;
    } else {
        REG_DISPSTAT &= ~0x8;
    }
    return prevStat;
}

void GX_DispOff(void) {
    u32 cnt      = REG_DISPCNT;
    GX_data_0004 = 0;
    GX_data_0002 = (cnt & 0x30000) >> 16;
    REG_DISPCNT  = cnt & ~0x30000;
}

void GX_DispOn(void) {
    GX_data_0004 = 1;
    if (GX_data_0002 != 0) {
        REG_DISPCNT = (REG_DISPCNT & ~0x30000) | GX_data_0002 << 16;
        return;
    }
    REG_DISPCNT |= 0x10000;
}

void GX_SetGraphicsMode(u32 param1, u32 param2, u32 param3) {
    u32 cnt      = REG_DISPCNT;
    GX_data_0002 = param1;
    if (GX_data_0004 == 0) {
        param1 = 0;
    }
    cnt         = (cnt & ~0xf000f) | (param1 << 16);
    REG_DISPCNT = param2 | cnt | (param3 << 3);
    if (GX_data_0002 == 0) {
        GX_data_0004 = 0;
    }
}

void GXS_SetGraphicsMode(u32 mode) {
    REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x7) | mode;
}

void GXx_SetMasterBrightness_(s16 *bright, s32 value) {
    if (value == 0) {
        *bright = 0;
    } else if (value > 0) {
        *bright = 0x4000 | value;
    } else {
        *bright = 0x8000 | -value;
    }
}

u32 GX_SetDefaultDMA(u32 dma) {
    u32 currDma;
    OSIntrMode irq;

    currDma = GX_defaultDma;
    if (currDma != -1) {
        MI_WaitDma(currDma);
    }

    irq           = OS_DisableInterrupts();
    GX_defaultDma = dma;
    OS_RestoreInterrupts(irq);
    return currDma;
}
