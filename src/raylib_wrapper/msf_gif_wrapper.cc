#include "msf_gif_wrapper.h"

int MsfGifBeginWrapper(MsfGifState *handle, int width, int height) {
  return msf_gif_begin(handle, width, height);
}

int MSfGifFrameWrapper(MsfGifState *handle, uint8_t *pixelData,
                       int centiSecondsPerFame, int maxBitDepth,
                       int pitchInBytes) {
  return msf_gif_frame(handle, pixelData, centiSecondsPerFame, maxBitDepth,
                       pitchInBytes);
}

MsfGifResult MsfGifEndWrapper(MsfGifState *handle) {
  return msf_gif_end(handle);
}

void MsfGifFreeWrapper(MsfGifResult result) { msf_gif_free(result); }