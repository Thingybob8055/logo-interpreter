#include "rl_recorder.h"

constexpr int gif_record_framerate = 10;

RLRecorder::RLRecorder(RLWindow* window) : window(window) {}

void RLRecorder::InitRecording() {
  if (!gif_recording) {
    gif_recording = true;
    gif_frame_counter = 0;
    Vector2 scale = GetWindowScaleDPIWrapper();

    msf_gif_beginWrapper(
        &gif_state, (int)((float)window->GetXMaxScreenCoordinate() * scale.x),
        (int)((float)window->GetYMaxScreenCoordinate() * scale.y));
  }
}

void RLRecorder::StartRecording() {
  if (gif_recording) {
    gif_frame_counter++;

    if ((gif_frame_counter % gif_record_framerate) == 0) {
      Vector2 scale = GetWindowScaleDPIWrapper();
      unsigned char* screen_data = rlReadScreenPixelsWrapper(
          (int)((float)window->GetXMaxScreenCoordinate() * scale.x),
          (int)((float)window->GetYMaxScreenCoordinate() * scale.y));
      msf_gif_frameWrapper(&gif_state, screen_data, 10, 16,
                           window->GetXMaxScreenCoordinate() * scale.x * 4);

      RL_FREE(screen_data);
    }
  }
}

void RLRecorder::SaveScreenshot() {
  if (IsKeyPressedWrapper(KEY_BACKSPACE)) {
    TakeScreenshotWrapper("./assets/logo.png");
  }
}

void RLRecorder::SaveRecording() {
  if (IsKeyPressedWrapper(KEY_ENTER)) {
    if (gif_recording) {
      gif_recording = false;

      MsfGifResult result = msf_gif_endWrapper(&gif_state);

      SaveFileDataWrapper("./out/logo.gif", result.data,
                          (unsigned int)result.dataSize);
      msf_gif_freeWrapper(result);
    }
  }
}