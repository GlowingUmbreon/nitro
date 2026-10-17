#ifndef _NITRO_GX_INIT_H
#define _NITRO_GX_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/types.h"

void GX_Init(void);

u32 GX_VBlankIntr(BOOL);
u16 GX_HBlankIntr(BOOL);

void GX_DispOff(void);
void GX_DispOn(void);

void GX_SetGraphicsMode(u32, u32, u32);
void GXS_SetGraphicsMode(u32);

void GXx_SetMasterBrightness_(s16 *bright, s32 value);

u32 GX_SetDefaultDMA(u32 dma);

extern u16 GX_data_0004;
extern u32 GX_defaultDma;

extern u16 GX_data_0002;
extern u16 GX_lockId;

#ifdef __cplusplus
}
#endif

#endif
