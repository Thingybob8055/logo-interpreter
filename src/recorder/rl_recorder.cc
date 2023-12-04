#include "rl_recorder.h"

constexpr int gif_record_framerate = 10;

RLRecorder::RLRecorder() {}

void RLRecorder::InitRecording() {
  if (!gifRecording) {
    gifRecording = true;
    gifFrameCounter = 0;

    msf_gif_begin(&gifState, (int)((float)screen_width),
                  (int)((float)screen_height));
  }
}

void RLRecorder::StartRecording() {
  if (gifRecording) {
    gifFrameCounter++;

    if ((gifFrameCounter % gif_record_framerate) == 0) {
      unsigned char* screenData = rlReadScreenPixelsWrapper(
          (int)((float)screen_width), (int)((float)screen_height));
      msf_gif_frame(&gifState, screenData, 10, 16, screen_width * 4);

      RL_FREE(screenData);
    }
  }
}

void RLRecorder::SaveRecording() {
  if (IsKeyPressedWrapper(KEY_ENTER)) {
    if (gifRecording) {
      gifRecording = false;

      MsfGifResult result = msf_gif_end(&gifState);

      SaveFileDataWrapper("./out/logo.gif", result.data,
                          (unsigned int)result.dataSize);
      msf_gif_free(result);

    }
  }
}