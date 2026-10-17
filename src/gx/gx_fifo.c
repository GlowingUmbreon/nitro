#include "nitro/gx/gx_fifo.h"
#include "nitro/fx.h"
#include "nitro/types.h"

THUMB_DISABLE();
void GX_SendFifo48B(const void *src, void *dst) {
#ifdef NITRO_NO_ASM
    *(MtxFx43 *) dst = *(MtxFx43 *) src;
#else
    // clang-format off
    asm {
        ldmia src!, {r2, r3, ip}
        stmia dst!, {r2, r3, ip}
        ldmia src!, {r2, r3, ip}
        stmia dst!, {r2, r3, ip}
        ldmia src!, {r2, r3, ip}
        stmia dst!, {r2, r3, ip}
        ldmia src!, {r2, r3, ip}
        stmia dst!, {r2, r3, ip}
    }
    // clang-format on
#endif
}

#ifdef NITRO_NO_ASM
void GX_SendFifo64B(const void *src, void *dst) {
    *(MtxFx44 *) dst = *(MtxFx44 *) src;
}
#else
// clang-format off
ASM void GX_SendFifo64B(const void *src, void *dst) {
    stmdb sp!, {r4-r8}
    ldmia r0!, {r2-r8, ip}
    stmia r1!, {r2-r8, ip}
    ldmia r0!, {r2-r8, ip}
    stmia r1!, {r2-r8, ip}
    ldmia sp!, {r4-r8}
    bx lr
}
// clang-format on
#endif
THUMB_ENABLE();
