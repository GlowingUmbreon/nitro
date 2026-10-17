#ifndef _NITRO_GX_FIFO_H
#define _NITRO_GX_FIFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/types.h"

void GX_SendFifo48B(const void *src, void *dst);
void GX_SendFifo64B(const void *src, void *dst);

#ifdef __cplusplus
}
#endif

#endif
