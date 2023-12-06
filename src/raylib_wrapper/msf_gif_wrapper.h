#ifndef MSF_GIF_H_
#define MSF_GIF_H_

#include "external/msf_gif.h"

#ifdef TEST
#define WEAK_REF __attribute__((weak))
#else
#define WEAK_REF
#endif

int WEAK_REF MsfGifBeginWrapper(MsfGifState *handle, int width, int height);
int WEAK_REF MSfGifFrameWrapper(MsfGifState *handle, uint8_t *pixelData,
                                int centiSecondsPerFame, int maxBitDepth,
                                int pitchInBytes);
MsfGifResult WEAK_REF MsfGifEndWrapper(MsfGifState *handle);
void WEAK_REF MsfGifFreeWrapper(MsfGifResult result);

#endif  // MSF_GIF_H_