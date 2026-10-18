#ifndef _NITRO_GX_OBJ_H
#define _NITRO_GX_OBJ_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/reg.h"
#include "nitro/types.h"

#define GX_OAM_MODE_XLU 1
#define GX_OAM_MODE_BITMAPOBJ 3

#define GX_OAM_EFFECT_NONE 0

#define GX_OAM_SHAPE_64x64 0x3

#define GX_OAM_COLOR_16 0xf

typedef struct {
    u32 attr01;
    union {
        u16 attr2;
        u32 attr23;
    };
} GXOamAttr;

typedef u32 GXOamMode;

inline void G2_SetOBJMosaicSize(u32 width, u32 height) {
    REG_OBJMOSAIC = width | (height << 4);
}

inline void G2S_SetOBJMosaicSize(u32 width, u32 height) {
    REG_OBJMOSAIC_SUB = width | (height << 4);
}

inline void G2_GetOBJPosition(GXOamAttr *oam, u32 *x, u32 *y) {
    *x = (oam->attr01 & 0x1ff0000) >> 16;
    *y = oam->attr01 & 0xff;
}

inline void G2_SetOBJPosition(GXOamAttr *oam, u32 x, u32 y) {
    oam->attr01 = (oam->attr01 & 0xfe00ff00) | (y & 0xff) | (x << 0x17 >> 0x7);
}

inline u32 G2_GetOBJCharName(GXOamAttr *oam) {
    return oam->attr2 & 0x3ff;
}

inline void G2_SetOBJCharName(volatile GXOamAttr *oam, u32 name) {
    oam->attr2 = (oam->attr2 & -0x400) | (name);
}

inline u32 G2_GetOBJColorParam(GXOamAttr *oam) {
    return (oam->attr2 & 0xf000) >> 0xc;
}

// Defined as macro as sometimes `oam` is volatile and other times not
#define G2_GetOBJMode(oam) (GXOamMode)(((oam)->attr01 & 0xc00) >> 0xa)
// inline GXOamMode G2_GetOBJMode(volatile GXOamAttr *oam) {
//     return ((oam)->attr01 & 0xc00) >> 0xa;
// }

inline void G2_SetOBJMode(GXOamAttr *oam, GXOamMode mode, u32 color) {
    oam->attr01 = (oam->attr01 & ~0xc00) | (mode << 0xa);
    oam->attr2  = (oam->attr2 & ~0xf000) | (color << 0xc);
}

inline void G2_SetOBJPriority(GXOamAttr *oam, u32 prio) {
    // no implementation found
}

inline void G2_SetOBJAttr(GXOamAttr *oam, u32 x, u32 y, u32 param4, GXOamMode mode, BOOL param6, u32 effect, u32 shape,
                          u32 color, u32 param10, u32 param11, u32 param12) {
    // Unused: param4, param6, effect, param11, param12

    // c1ff0cff
    // 3 bits at 0x8
    // 4 bits at 0xc
    // 5 bits at 0x19
    oam->attr01 = (y & 0xff) | (mode << 0xa) | (shape << 0x1e) | ((x << 0x17) >> 0x7);
    // f3ff
    // 2 bits at 0xa
    oam->attr2 = param10 | (color << 0xc);
}

#ifdef __cplusplus
}
#endif

#endif
