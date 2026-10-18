#ifndef _NITRO_GX_BANK_H
#define _NITRO_GX_BANK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/types.h"

void GX_SetBankForBG(s32 bank);
void GX_SetBankForOBJ(s32 bank);
void GX_SetBankForBGExtPltt(s32 bank);
void GX_SetBankForOBJExtPltt(s32 bank);
void GX_SetBankForTex(s32 bank);
void GX_SetBankForTexPltt(s32 bank);
void GX_SetBankForClearImage(s32 bank);
void GX_SetBankForARM7(s32 bank);
void GX_SetBankForLCDC(s32 bank);
void GX_SetBankForSubBG(s32 bank);
void GX_SetBankForSubOBJ(s32 bank);
void GX_SetBankForSubBGExtPltt(s32 bank);
void GX_SetBankForSubOBJExtPltt(s32 bank);

BOOL GX_TrySetBankForBGExtPltt(s32);
BOOL GX_TrySetBankForSubBGExtPltt(s32);
BOOL GX_TrySetBankForOBJExtPltt(s32);
BOOL GX_TrySetBankForSubOBJExtPltt(s32);

u16 GX_DisableBankForBG(void);
u16 GX_DisableBankForOBJ(void);
u16 GX_DisableBankForBGExtPltt(void);
u16 GX_DisableBankForOBJExtPltt(void);
u16 GX_DisableBankForTex(void);
u16 GX_DisableBankForTexPltt(void);
u16 GX_DisableBankForClearImage(void);
u16 GX_DisableBankForARM7(void);
u16 GX_DisableBankForLCDC(void);
u16 GX_DisableBankForSubBG(void);
u16 GX_DisableBankForSubOBJ(void);
u16 GX_DisableBankForSubBGExtPltt(void);
u16 GX_DisableBankForSubOBJExtPltt(void);

u16 GX_ResetBankForTex(void);
u16 GX_ResetBankForBGExtPltt(void);
u16 GX_ResetBankForSubBGExtPltt(void);
u16 GX_ResetBankForOBJExtPltt(void);
u16 GX_ResetBankForSubOBJExtPltt(void);
u16 GX_ResetBankForTexPltt(void);
u16 GX_ResetBankForSubOBJ(void);

#ifdef __cplusplus
}
#endif

#endif
