#include "rl_recorder.h"

constexpr int gif_record_framerate = 10;

RLRecorder::RLRecorder(RLWindow* window) : window(window) {}

void RLRecorder::InitRecording() {
  if (!gifRecording) {
    gifRecording = true;
    gifFrameCounter = 0;
    Vector2 scale = GetWindowScaleDPIWrapper();

    msf_gif_beginWrapper(
        &gifState, (int)((float)window->GetXMaxScreenCoordinate() * scale.x),
        (int)((float)window->GetYMaxScreenCoordinate() * scale.y));
  }
}

void RLRecorder::StartRecording() {
  if (gifRecording) {
    gifFrameCounter++;

    if ((gifFrameCounter % gif_record_framerate) == 0) {
      Vector2 scale = GetWindowScaleDPIWrapper();
      unsigned char* screenData = rlReadScreenPixelsWrapper(
          (int)((float)window->GetXMaxScreenCoordinate() * scale.x),
          (int)((float)window->GetYMaxScreenCoordinate() * scale.y));
      msf_gif_frameWrapper(&gifState, screenData, 10, 16,
                           window->GetXMaxScreenCoordinate() * scale.x * 4);

      RL_FREE(screenData);
    }
  }
}

void RLRecorder::SaveRecording() {
  if (IsKeyPressedWrapper(KEY_ENTER)) {
    if (gifRecording) {
      gifRecording = false;
      ;
      MsfGifResult result = msf_gif_endWrapper(&gifState);

      SaveFileDataWrapper("./out/logo.gif", result.data,
                          (unsigned int)result.dataSize);
      msf_gif_freeWrapper(result);
    }
  }
  if(IsKeyPressedWrapper(KEY_BACKSPACE)) {
    TakeScreenshotWrapper("./out/logo.png");
  }
}