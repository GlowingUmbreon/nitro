#ifndef _NITRO_GX_LOAD_H
#define _NITRO_GX_LOAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/gx/gx_obj.h"
#include "nitro/types.h"

void GX_LoadOAM(GXOamAttr *oam, u32 offset, u32 size);
void GXS_LoadOAM(GXOamAttr *oam, u32 offset, u32 size);

void GX_LoadBG0Char(void *ptr, u32 offset, u32 size);
void GX_LoadBG0Scr(void *ptr, u32 offset, u32 size);
void GX_LoadBG1Char(void *ptr, u32 offset, u32 size);
void GX_LoadBG1Scr(void *ptr, u32 offset, u32 size);
void GX_LoadBG2Bmp(void *ptr, u32 offset, u32 size);
void GX_LoadBG2Char(void *ptr, u32 offset, u32 size);
void GX_LoadBG2Scr(void *ptr, u32 offset, u32 size);
void GX_LoadBG3Bmp(void *ptr, u32 offset, u32 size);
void GX_LoadBG3Char(void *ptr, u32 offset, u32 size);
void GX_LoadBG3Scr(void *ptr, u32 offset, u32 size);

void GXS_LoadBG0Char(void *ptr, u32 offset, u32 size);
void GXS_LoadBG0Scr(void *ptr, u32 offset, u32 size);
void GXS_LoadBG1Char(void *ptr, u32 offset, u32 size);
void GXS_LoadBG1Scr(void *ptr, u32 offset, u32 size);
void GXS_LoadBG2Bmp(void *ptr, u32 offset, u32 size);
void GXS_LoadBG2Char(void *ptr, u32 offset, u32 size);
void GXS_LoadBG2Scr(void *ptr, u32 offset, u32 size);
void GXS_LoadBG3Bmp(void *ptr, u32 offset, u32 size);
void GXS_LoadBG3Char(void *ptr, u32 offset, u32 size);
void GXS_LoadBG3Scr(void *ptr, u32 offset, u32 size);

void GX_LoadBGPltt(void *ptr, u32 offset, u32 size);
void GX_LoadOBJPltt(void *ptr, u32 offset, u32 size);
void GXS_LoadBGPltt(void *ptr, u32 offset, u32 size);
void GXS_LoadOBJPltt(void *ptr, u32 offset, u32 size);

void GX_LoadOBJ(void *ptr, u32 offset, u32 size);
void GXS_LoadOBJ(void *ptr, u32 offset, u32 size);

void GX_BeginLoadBGExtPltt(void);
void GX_LoadBGExtPltt(void *ptr, u32 offset, u32 size);
void GX_EndLoadBGExtPltt(void);

void GXS_BeginLoadBGExtPltt(void);
void GXS_LoadBGExtPltt(void *ptr, u32 offset, u32 size);
void GXS_EndLoadBGExtPltt(void);

void GX_BeginLoadOBJExtPltt(void);
void GX_LoadOBJExtPltt(void *ptr, u32 offset, u32 size);
void GX_EndLoadOBJExtPltt(void);

void GXS_BeginLoadOBJExtPltt(void);
void GXS_LoadOBJExtPltt(void *ptr, u32 offset, u32 size);
void GXS_EndLoadOBJExtPltt(void);

void GX_BeginLoadTexPltt(void);
void GX_LoadTexPltt(void *ptr, u32 offset, u32 size);
void GX_EndLoadTexPltt(void);

void GX_BeginLoadTex(void);
void GX_LoadTex(void *ptr, u32 offset, u32 size);
void GX_EndLoadTex(void);

#ifdef __cplusplus
}
#endif

#endif
