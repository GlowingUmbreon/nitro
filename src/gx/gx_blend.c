#include "nitro/gx/gx_blend.h"
#include "nitro/reg.h"

void G2x_SetBlendBrightness_(REGBlend *blend, s32 cnt, s32 brightness) {
    if (brightness < 0) {
        blend->cnt        = cnt | 0xC0;
        blend->brightness = -brightness;
    } else {
        blend->cnt        = cnt | 0x80;
        blend->brightness = brightness;
    }
}

void G2x_ChangeBlendBrightness_(REGBlend *blend, s32 brightness) {
    u16 cnt;

    cnt = blend->cnt;
    if (brightness < 0) {
        if ((cnt & 0xC0) == 0x80) {
            blend->cnt = (cnt & ~0xC0) | 0xC0;
        }
        blend->brightness = -brightness;
    } else {
        if ((cnt & 0xC0) == 0xC0) {
            blend->cnt = (cnt & ~0xC0) | 0x80;
        }
        blend->brightness = brightness;
    }
}

void _G2_SetBlend(u32 *reg, u32 srcPlane, u32 dstPlane, u32 srcAlpha, u32 dstAlpha) {
    u32 plane = srcPlane | 0x40 | (dstPlane << 8);
    u32 alpha = srcAlpha | (dstAlpha << 8);
    *reg      = plane | (alpha << 16);
}
