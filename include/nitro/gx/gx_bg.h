#ifndef _NITRO_GX_BG_H
#define _NITRO_GX_BG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/fx.h"
#include "nitro/reg.h"
#include "nitro/types.h"

#define GX_BGCHAROFFSET_0x00000 0
#define GX_BGSCROFFSET_0x00000 0
#define GX_BGMODE_0 0
#define GX_BGMODE_3 3
#define GX_BGMODE_5 5
#define GX_BG0_AS_2D 0
#define GX_BG_SCRSIZE_TEXT_256x256 0
#define GX_BG_SCRSIZE_256BMP_128x128 ((GXBGScrSize256Bmp) 0)
#define GX_BG_SCRSIZE_256BMP_256x256 ((GXBGScrSize256Bmp) 1)
#define GX_BG_SCRSIZE_256BMP_512x256 ((GXBGScrSize256Bmp) 2)
#define GX_BG_SCRSIZE_256BMP_512x512 ((GXBGScrSize256Bmp) 3)
#define GX_BG_SCRSIZE_DCBMP_128x128 ((GXBGScrSizeDcBmp) 0)
#define GX_BG_SCRSIZE_DCBMP_256x256 ((GXBGScrSizeDcBmp) 1)
#define GX_BG_SCRSIZE_DCBMP_512x256 ((GXBGScrSizeDcBmp) 2)
#define GX_BG_SCRSIZE_DCBMP_512x512 ((GXBGScrSizeDcBmp) 3)
#define GX_BG_AREAOVER_XLU ((GXBGAreaOver) 0)
#define GX_BG_AREAOVER_REPEAT ((GXBGAreaOver) 1)
#define GX_BG_BMPSCRBASE_0x00000 ((GXBGBmpScrBase) 0)
#define GX_BG_BMPSCRBASE_0x04000 ((GXBGBmpScrBase) 1)
#define GX_BG_BMPSCRBASE_0x08000 ((GXBGBmpScrBase) 2)
#define GX_BG_BMPSCRBASE_0x0c000 ((GXBGBmpScrBase) 3)
#define GX_BG_BMPSCRBASE_0x10000 ((GXBGBmpScrBase) 4)
#define GX_BG_BMPSCRBASE_0x14000 ((GXBGBmpScrBase) 5)
#define GX_BG_BMPSCRBASE_0x18000 ((GXBGBmpScrBase) 6)
#define GX_BG_BMPSCRBASE_0x1c000 ((GXBGBmpScrBase) 7)
#define GX_BG_BMPSCRBASE_0x20000 ((GXBGBmpScrBase) 8)
#define GX_BG_BMPSCRBASE_0x24000 ((GXBGBmpScrBase) 9)
#define GX_BG_BMPSCRBASE_0x28000 ((GXBGBmpScrBase) 10)
#define GX_BG_BMPSCRBASE_0x2c000 ((GXBGBmpScrBase) 11)
#define GX_BG_BMPSCRBASE_0x30000 ((GXBGBmpScrBase) 12)
#define GX_BG_BMPSCRBASE_0x34000 ((GXBGBmpScrBase) 13)
#define GX_BG_BMPSCRBASE_0x38000 ((GXBGBmpScrBase) 14)
#define GX_BG_BMPSCRBASE_0x3c000 ((GXBGBmpScrBase) 15)
#define GX_BG_BMPSCRBASE_0x40000 ((GXBGBmpScrBase) 16)
#define GX_BG_BMPSCRBASE_0x44000 ((GXBGBmpScrBase) 17)
#define GX_BG_BMPSCRBASE_0x48000 ((GXBGBmpScrBase) 18)
#define GX_BG_BMPSCRBASE_0x4c000 ((GXBGBmpScrBase) 19)
#define GX_BG_BMPSCRBASE_0x50000 ((GXBGBmpScrBase) 20)
#define GX_BG_BMPSCRBASE_0x54000 ((GXBGBmpScrBase) 21)
#define GX_BG_BMPSCRBASE_0x58000 ((GXBGBmpScrBase) 22)
#define GX_BG_BMPSCRBASE_0x5c000 ((GXBGBmpScrBase) 23)
#define GX_BG_BMPSCRBASE_0x60000 ((GXBGBmpScrBase) 24)
#define GX_BG_BMPSCRBASE_0x64000 ((GXBGBmpScrBase) 25)
#define GX_BG_BMPSCRBASE_0x68000 ((GXBGBmpScrBase) 26)
#define GX_BG_BMPSCRBASE_0x6c000 ((GXBGBmpScrBase) 27)
#define GX_BG_BMPSCRBASE_0x70000 ((GXBGBmpScrBase) 28)
#define GX_BG_BMPSCRBASE_0x74000 ((GXBGBmpScrBase) 29)
#define GX_BG_BMPSCRBASE_0x78000 ((GXBGBmpScrBase) 30)
#define GX_BG_BMPSCRBASE_0x7c000 ((GXBGBmpScrBase) 31)
#define GX_BG_COLORMODE_16 0
#define GX_BG_CHARBASE_0x00000 0
#define GX_BG_SCRBASE_0x0000 0
#define GX_BG_EXTPLTT_01 1

typedef u32 GXBGScrSize256Bmp;
typedef u32 GXBGScrSizeDcBmp;
typedef u32 GXBGAreaOver;
typedef u32 GXBGBmpScrBase;
typedef u32 GXBGScrSizeText;
typedef u32 GXBGColorMode;
typedef u32 GXBGScrBase;
typedef u32 GXBGCharBase;

void *G2_GetBG0ScrPtr(void);
void *G2S_GetBG0ScrPtr(void);
void *G2_GetBG1ScrPtr(void);
void *G2S_GetBG1ScrPtr(void);
void *G2_GetBG2ScrPtr(void);
void *G2S_GetBG2ScrPtr(void);
void *G2_GetBG3ScrPtr(void);
void *G2S_GetBG3ScrPtr(void);
void *G2_GetBG0CharPtr(void);
void *G2S_GetBG0CharPtr(void);
void *G2_GetBG1CharPtr(void);
void *G2S_GetBG1CharPtr(void);
void *G2_GetBG2CharPtr(void);
void *G2S_func_0005(void);
void *G2_GetBG3CharPtr(void);
void *G2S_func_0006(void);

void G2x_SetBGyAffine_(u32 *reg, MtxFx22 *mtx, s32 x0, s32 y0, s32 x1, s32 y1);

inline void G2_SetBG0Priority(u32 value) {
    REG_BG0CNT = (REG_BG0CNT & ~0x3) | (value);
}

inline void G2_SetBG1Priority(u32 value) {
    REG_BG1CNT = (REG_BG1CNT & ~0x3) | (value);
}

inline void G2_SetBG2Priority(u32 value) {
    REG_BG2CNT = (REG_BG2CNT & ~0x3) | (value);
}

inline void G2_SetBG3Priority(u32 value) {
    REG_BG3CNT = (REG_BG3CNT & ~0x3) | (value);
}

inline void G2S_SetBG0Priority(u32 value) {
    REG_BG0CNT_SUB = (REG_BG0CNT_SUB & ~0x3) | (value);
}

inline void G2S_SetBG1Priority(u32 value) {
    REG_BG1CNT_SUB = (REG_BG1CNT_SUB & ~0x3) | (value);
}

inline void G2S_SetBG2Priority(u32 value) {
    REG_BG2CNT_SUB = (REG_BG2CNT_SUB & ~0x3) | (value);
}

inline void G2S_SetBG3Priority(u32 value) {
    REG_BG3CNT_SUB = (REG_BG3CNT_SUB & ~0x3) | (value);
}

inline void G2_SetBG0Offset(u32 x, u32 y) {
    REG_BG0OFS = (x & 0x1ff) | ((y << 16) & 0x1ff0000);
}

inline void G2_SetBG1Offset(u32 x, u32 y) {
    REG_BG1OFS = (x & 0x1ff) | ((y << 16) & 0x1ff0000);
}

inline void G2_SetBG2Offset(u32 x, u32 y) {
    REG_BG2OFS = (x & 0x1ff) | ((y << 16) & 0x1ff0000);
}

inline void G2_SetBG3Offset(u32 x, u32 y) {
    REG_BG3OFS = (x & 0x1ff) | ((y << 16) & 0x1ff0000);
}

inline void G2S_SetBG0Offset(u32 x, u32 y) {
    REG_BG0OFS_SUB = (x & 0x1ff) | ((y << 16) & 0x1ff0000);
}

inline void G2S_SetBG1Offset(u32 x, u32 y) {
    REG_BG1OFS_SUB = (x & 0x1ff) | ((y << 16) & 0x1ff0000);
}

inline void G2S_SetBG2Offset(u32 x, u32 y) {
    REG_BG2OFS_SUB = (x & 0x1ff) | ((y << 16) & 0x1ff0000);
}

inline void G2S_SetBG3Offset(u32 x, u32 y) {
    REG_BG3OFS_SUB = (x & 0x1ff) | ((y << 16) & 0x1ff0000);
}

inline void G2_SetBG0Control(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase, GXBGCharBase charBase,
                             u32) {
    REG_BG0CNT = (REG_BG0CNT & 0x43) | (scrSize << 0xe) | (colMode << 0x7) | (scrBase << 0x8) | (charBase << 0x2);
}

inline void G2_SetBG1Control(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase, GXBGCharBase charBase,
                             u32) {
    REG_BG1CNT = (REG_BG1CNT & 0x43) | (scrSize << 0xe) | (colMode << 0x7) | (scrBase << 0x8) | (charBase << 0x2);
}

inline void G2_SetBG2Control(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase, GXBGCharBase charBase,
                             u32) {
    REG_BG2CNT = (REG_BG2CNT & 0x43) | (scrSize << 0xe) | (colMode << 0x7) | (scrBase << 0x8) | (charBase << 0x2);
}

inline void G2_SetBG3Control(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase, GXBGCharBase charBase,
                             u32) {
    REG_BG3CNT = (REG_BG3CNT & 0x43) | (scrSize << 0xe) | (colMode << 0x7) | (scrBase << 0x8) | (charBase << 0x2);
}

inline void G2S_SetBG0Control(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase,
                              GXBGCharBase charBase, u32) {
    REG_BG0CNT_SUB =
        (REG_BG0CNT_SUB & 0x43) | (scrSize << 0xe) | (colMode << 0x7) | (scrBase << 0x8) | (charBase << 0x2);
}

inline void G2S_SetBG1Control(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase,
                              GXBGCharBase charBase, u32) {
    REG_BG1CNT_SUB =
        (REG_BG1CNT_SUB & 0x43) | (scrSize << 0xe) | (colMode << 0x7) | (scrBase << 0x8) | (charBase << 0x2);
}

inline void G2S_SetBG2Control(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase,
                              GXBGCharBase charBase, u32) {
    REG_BG2CNT_SUB =
        (REG_BG2CNT_SUB & 0x43) | (scrSize << 0xe) | (colMode << 0x7) | (scrBase << 0x8) | (charBase << 0x2);
}

inline void G2S_SetBG3Control(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase,
                              GXBGCharBase charBase, u32) {
    REG_BG3CNT_SUB =
        (REG_BG3CNT_SUB & 0x43) | (scrSize << 0xe) | (colMode << 0x7) | (scrBase << 0x8) | (charBase << 0x2);
}

inline void G2_SetBG2Control256Bmp(GXBGScrSize256Bmp scrSize, GXBGAreaOver areaOver, GXBGBmpScrBase scrBase) {
    REG_BG2CNT = (REG_BG2CNT & 0x43) | (scrSize << 0xe) | 0x80 | (scrBase << 0x8) | (areaOver << 0xd);
}

inline void G2_SetBG3Control256Bmp(GXBGScrSize256Bmp scrSize, GXBGAreaOver areaOver, GXBGBmpScrBase scrBase) {
    REG_BG3CNT = (REG_BG3CNT & 0x43) | (scrSize << 0xe) | 0x80 | (scrBase << 0x8) | (areaOver << 0xd);
}

inline void G2S_SetBG2Control256Bmp(GXBGScrSize256Bmp scrSize, GXBGAreaOver areaOver, GXBGBmpScrBase scrBase) {
    REG_BG2CNT_SUB = (REG_BG2CNT_SUB & 0x43) | (scrSize << 0xe) | 0x80 | (scrBase << 0x8) | (areaOver << 0xd);
}

inline void G2S_SetBG3Control256Bmp(GXBGScrSize256Bmp scrSize, GXBGAreaOver areaOver, GXBGBmpScrBase scrBase) {
    REG_BG3CNT_SUB = (REG_BG3CNT_SUB & 0x43) | (scrSize << 0xe) | 0x80 | (scrBase << 0x8) | (areaOver << 0xd);
}

inline void G2_SetBG2ControlDCBmp(GXBGScrSizeDcBmp scrSize, GXBGAreaOver areaOver, GXBGBmpScrBase scrBase) {
    REG_BG2CNT = (REG_BG2CNT & 0x43) | (scrSize << 0xe) | 0x84 | (scrBase << 0x8) | (areaOver << 0xd);
}

inline void G2_SetBG3ControlDCBmp(GXBGScrSizeDcBmp scrSize, GXBGAreaOver areaOver, GXBGBmpScrBase scrBase) {
    REG_BG3CNT = (REG_BG3CNT & 0x43) | (scrSize << 0xe) | 0x84 | (scrBase << 0x8) | (areaOver << 0xd);
}

inline void G2S_SetBG2ControlDCBmp(GXBGScrSizeDcBmp scrSize, GXBGAreaOver areaOver, GXBGBmpScrBase scrBase) {
    REG_BG2CNT_SUB = (REG_BG2CNT_SUB & 0x43) | (scrSize << 0xe) | 0x84 | (scrBase << 0x8) | (areaOver << 0xd);
}

inline void G2S_SetBG3ControlDCBmp(GXBGScrSizeDcBmp scrSize, GXBGAreaOver areaOver, GXBGBmpScrBase scrBase) {
    REG_BG3CNT_SUB = (REG_BG3CNT_SUB & 0x43) | (scrSize << 0xe) | 0x84 | (scrBase << 0x8) | (areaOver << 0xd);
}

inline void G2_SetBG2ControlText(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase,
                                 GXBGCharBase charBase) {
    G2_SetBG2Control(scrSize, colMode, scrBase, charBase, 0);
}

inline void G2_SetBG3ControlText(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase,
                                 GXBGCharBase charBase) {
    G2_SetBG3Control(scrSize, colMode, scrBase, charBase, 0);
}

inline void G2S_SetBG2ControlText(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase,
                                  GXBGCharBase charBase) {
    G2S_SetBG2Control(scrSize, colMode, scrBase, charBase, 0);
}

inline void G2S_SetBG3ControlText(GXBGScrSizeText scrSize, GXBGColorMode colMode, GXBGScrBase scrBase,
                                  GXBGCharBase charBase) {
    G2S_SetBG3Control(scrSize, colMode, scrBase, charBase, 0);
}

inline void G2_SetBG2Affine(MtxFx22 *mtx, u32 param2, u32 param3, u32 param4, u32 param5) {
    G2x_SetBGyAffine_((u32 *) &REG_BG2PA, mtx, param2, param3, param4, param5);
}

inline void G2_SetBG3Affine(MtxFx22 *mtx, u32 param2, u32 param3, u32 param4, u32 param5) {
    G2x_SetBGyAffine_((u32 *) &REG_BG3PA, mtx, param2, param3, param4, param5);
}

inline void G2S_SetBG2Affine(MtxFx22 *mtx, u32 param2, u32 param3, u32 param4, u32 param5) {
    G2x_SetBGyAffine_((u32 *) &REG_BG2PA_SUB, mtx, param2, param3, param4, param5);
}

inline void G2S_SetBG3Affine(MtxFx22 *mtx, u32 param2, u32 param3, u32 param4, u32 param5) {
    G2x_SetBGyAffine_((u32 *) &REG_BG3PA_SUB, mtx, param2, param3, param4, param5);
}
inline void G2_BG0Mosaic(BOOL flag) {
    if (flag) {
        REG_BG0CNT |= 0x40;
    } else {
        REG_BG0CNT &= ~0x40;
    }
}

inline void G2_BG1Mosaic(BOOL flag) {
    if (flag) {
        REG_BG1CNT |= 0x40;
    } else {
        REG_BG1CNT &= ~0x40;
    }
}

inline void G2_BG2Mosaic(BOOL flag) {
    if (flag) {
        REG_BG2CNT |= 0x40;
    } else {
        REG_BG2CNT &= ~0x40;
    }
}

inline void G2_BG3Mosaic(BOOL flag) {
    if (flag) {
        REG_BG3CNT |= 0x40;
    } else {
        REG_BG3CNT &= ~0x40;
    }
}

inline void G2S_BG0Mosaic(BOOL flag) {
    if (flag) {
        REG_BG0CNT_SUB |= 0x40;
    } else {
        REG_BG0CNT_SUB &= ~0x40;
    }
}

inline void G2S_BG1Mosaic(BOOL flag) {
    if (flag) {
        REG_BG1CNT_SUB |= 0x40;
    } else {
        REG_BG1CNT_SUB &= ~0x40;
    }
}

inline void G2S_BG2Mosaic(BOOL flag) {
    if (flag) {
        REG_BG2CNT_SUB |= 0x40;
    } else {
        REG_BG2CNT_SUB &= ~0x40;
    }
}

inline void G2S_BG3Mosaic(BOOL flag) {
    if (flag) {
        REG_BG3CNT_SUB |= 0x40;
    } else {
        REG_BG3CNT_SUB &= ~0x40;
    }
}

inline void G2_SetBGMosaicSize(u32 width, u32 height) {
    REG_MOSAIC = width | (height << 4);
}

inline void G2S_SetBGMosaicSize(u32 width, u32 height) {
    REG_MOSAIC_SUB = width | (height << 4);
}

inline void GX_SetBGCharOffset(u32 offset) {
    REG_DISPCNT = (REG_DISPCNT & ~0x7000000) | offset;
}

inline void GX_SetBGScrOffset(u32 offset) {
    REG_DISPCNT = (REG_DISPCNT & ~0x38000000) | offset;
}

#ifdef __cplusplus
}
#endif

#endif
