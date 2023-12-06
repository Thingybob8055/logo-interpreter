#include "rl_recorder.h"

constexpr int gif_record_framerate = 10;

RLRecorder::RLRecorder(RLWindow* window) : window(window) {}

void RLRecorder::InitRecording() {
  if (!gifRecording) {
    gifRecording = true;
    gifFrameCounter = 0;
    Vector2 scale = GetWindowScaleDPIWrapper();

    MsfGifBeginWrapper(&gifState,
                  (int)((float)window->GetXMaxScreenCoordinate() * scale.x),
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
      MSfGifFrameWrapper(&gifState, screenData, 10, 16,
                    window->GetXMaxScreenCoordinate() * scale.x * 4);

      RL_FREE(screenData);
    }
  }
}

void RLRecorder::SaveRecording() {
  if (IsKeyPressedWrapper(KEY_ENTER)) {
    if (gifRecording) {
      gifRecording = false;

      MsfGifResult result = MsfGifEndWrapper(&gifState);

      SaveFileDataWrapper("./out/logo.gif", result.data,
                          (unsigned int)result.dataSize);
      MsfGifFreeWrapper(result);
    }
  }
}