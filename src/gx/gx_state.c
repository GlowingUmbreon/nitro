#include "nitro/gx/gx_state.h"
#include "nitro/reg.h"

GX_UnkStruct2 GX_banks;

void GX_InitGXState(void) {
    GX_banks.lcdc          = 0;
    GX_banks.bg            = 0;
    GX_banks.obj           = 0;
    GX_banks.arm7          = 0;
    GX_banks.tex           = 0;
    GX_banks.texPltt       = 0;
    GX_banks.clearImage    = 0;
    GX_banks.bgExtPltt     = 0;
    GX_banks.objExtPltt    = 0;
    GX_banks.subBg         = 0;
    GX_banks.subObj        = 0;
    GX_banks.subBgExtPltt  = 0;
    GX_banks.subObjExtPltt = 0;
    REG_VRAM_CNT_ABCD      = 0;
    REG_VRAM_CNT_E         = 0;
    REG_VRAM_CNT_F         = 0;
    REG_VRAM_CNT_G         = 0;
    REG_VRAM_CNT_HI        = 0;
}