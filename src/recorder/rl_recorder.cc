#include "rl_recorder.h"

constexpr int gif_record_framerate = 10;

RLRecorder::RLRecorder() {}

void RLRecorder::InitRecording() {
  if (!gifRecording) {
    gifRecording = true;
    gifFrameCounter = 0;
    Vector2 scale = GetWindowScaleDPIWrapper();

    msf_gif_begin(&gifState, (int)((float)screen_width*scale.x),
                  (int)((float)screen_height*scale.y));
  }
}

void RLRecorder::StartRecording() {
  if (gifRecording) {
    gifFrameCounter++;

    if ((gifFrameCounter % gif_record_framerate) == 0) {
      Vector2 scale = GetWindowScaleDPIWrapper();
      unsigned char* screenData = rlReadScreenPixelsWrapper(
          (int)((float)screen_width*scale.x), (int)((float)screen_height*scale.y));
      msf_gif_frame(&gifState, screenData, 10, 16, screen_width*scale.x * 4);

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