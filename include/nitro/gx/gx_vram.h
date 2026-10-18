#ifndef _NITRO_GX_VRAM_H
#define _NITRO_GX_VRAM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/reg.h"
#include "nitro/types.h"

#define GX_VRAM_LCDC_ALL 0x1ff
#define GX_VRAM_LCDC_C 0x4
#define GX_VRAM_LCDC_D 0x8

#define GX_VRAM_BG_NONE ((GXVRamBG) 0)
#define GX_VRAM_BG_128_A ((GXVRamBG) 0x1)
#define GX_VRAM_BG_128_B ((GXVRamBG) 0x2)
#define GX_VRAM_BG_128_C ((GXVRamBG) 0x4)
#define GX_VRAM_BG_128_D ((GXVRamBG) 0x8)
#define GX_VRAM_BG_256_AB ((GXVRamBG) 0x3)
#define GX_VRAM_BG_384_ABC ((GXVRamBG) 0x7)
#define GX_VRAM_BG_384_ABD ((GXVRamBG) 0xb)
#define GX_VRAM_BG_512_ABCD ((GXVRamBG) 0xf)

#define GX_VRAM_SUB_BG_NONE ((GXVRamBG) 0)
#define GX_VRAM_SUB_BG_32_H ((GXVRamBG) 0x80)
#define GX_VRAM_SUB_BG_48_HI ((GXVRamBG) 0x180)
#define GX_VRAM_SUB_BG_128_C ((GXVRamBG) 0x4)

#define GX_VRAM_OBJ_NONE ((GXVRamOBJ) 0)
#define GX_VRAM_OBJ_128_A ((GXVRamOBJ) 0x1)
#define GX_VRAM_OBJ_128_B ((GXVRamOBJ) 0x2)
#define GX_VRAM_OBJ_128_C ((GXVRamOBJ) 0x4)
#define GX_VRAM_OBJ_128_D ((GXVRamOBJ) 0x8)
#define GX_VRAM_OBJ_64_E ((GXVRamOBJ) 0x10)
#define GX_VRAM_OBJ_16_F ((GXVRamOBJ) 0x20)
#define GX_VRAM_OBJ_16_G ((GXVRamOBJ) 0x40)

#define GX_VRAM_SUB_OBJ_NONE ((GXVRamOBJ) 0)
#define GX_VRAM_SUB_OBJ_16_I ((GXVRamOBJ) 0x100)
#define GX_VRAM_SUB_OBJ_128_D ((GXVRamOBJ) 0x8)

#define GX_VRAM_BGEXTPLTT_01_F 0x20
#define GX_VRAM_BGEXTPLTT_0123_FG 0x60
#define GX_VRAM_SUB_BGEXTPLTT_0123_H 0x80
#define GX_VRAM_SUB_OBJEXTPLTT_0_I 0x100
#define GX_VRAM_OBJEXTPLTT_0_F 0x20
#define GX_VRAM_OBJEXTPLTT_0_G 0x40

#define GX_VRAM_TEX_01_AB 0x3

#define GX_VRAM_TEXPLTT_0123_E 0x10

#define GX_OBJVRAMMODE_CHAR_1D_32K 0x10
#define GX_OBJVRAMMODE_CHAR_1D_64K 0x100010
#define GX_OBJVRAMMODE_CHAR_1D_128K 0x200010
#define GX_OBJVRAMMODE_CHAR_1D_256K 0x300010

typedef u32 GXVRamBG;
typedef u32 GXVRamOBJ;

typedef u32 GXOBJVRamModeChar;

inline void GX_SetOBJVRamModeChar(u32 value) {
    REG_DISPCNT = (REG_DISPCNT & 0xFFCFFFEF) | (value);
}

inline void GXS_SetOBJVRamModeChar(u32 value) {
    REG_DISPCNT_SUB = (REG_DISPCNT_SUB & 0xFFCFFFEF) | (value);
}

inline void GXS_SetOBJVRamModeBmp(u32 mode) {
    REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x60) | ((mode & 0x3) << 5);
}

#ifdef __cplusplus
}
#endif

#endif
