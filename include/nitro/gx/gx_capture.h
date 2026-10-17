#ifndef _NITRO_GX_CAPTURE_H
#define _NITRO_GX_CAPTURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/reg.h"
#include "nitro/types.h"

#define GX_CAPTURE_SIZE_256x192 -1 // unknown value
#define GX_CAPTURE_MODE_A -1 // unknown value
#define GX_CAPTURE_SRCA_2D3D -1 // unknown value
#define GX_CAPTURE_DEST_VRAM_C_0x00000 0x2
#define GX_CAPTURE_DEST_VRAM_D_0x00000 0x3

typedef u32 GXCaptureSrcB;

inline void GX_SetCapture(u32 size, u32 mode, u32 srcA, GXCaptureSrcB srcB, u32 dest, u32 param6, u32 param7) {
    // Unclear how to combine the arguments
    //   size = GX_CAPTURE_SIZE_256x192,
    //   mode = GX_CAPTURE_MODE_A,
    //   srcA = GX_CAPTURE_SRCA_2D3D,
    //   srcB = 0,
    //   dest = GX_CAPTURE_DEST_VRAM_C_0x00000,
    //   param6 = 16,
    //   param7 = 0,
    //     => 0x80320010
    REG_DISPCAPCNT = 0x80300010 | (dest << 0x10);
}

#ifdef __cplusplus
}
#endif

#endif
