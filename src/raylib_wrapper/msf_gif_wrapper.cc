#include "msf_gif_wrapper.h"

WRAPPER_FUNCTION(int, msf_gif_begin, MsfGifState *, handle, int, width, int,
                 height)

WRAPPER_FUNCTION(int, msf_gif_frame, MsfGifState *, handle, uint8_t *,
                 pixelData, int, centiSecondsPerFame, int, maxBitDepth, int,
                 pitchInBytes)

WRAPPER_FUNCTION(MsfGifResult, msf_gif_end, MsfGifState *, handle)

WRAPPER_FUNCTION(void, msf_gif_free, MsfGifResult, result)