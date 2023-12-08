#ifndef RL_RECORDER_H_
#define RL_RECORDER_H_

#include <raylib_wrapper/raylib_wrapper.h>

#include "raylib_wrapper/msf_gif_wrapper.h"
#include "recorder.h"
#include "window/rl_window.h"

class RLRecorder : public Recorder {
 private:
  RLWindow* window;

 public:
  RLRecorder(RLWindow* window);

  void InitRecording() override;
  void StartRecording() override;
  void SaveRecording() override;
  void SaveScreenshot() override;

 private:
  int gifFrameCounter = 0;
  bool gifRecording = false;
  MsfGifState gifState = {0};
};

#endif /* RL_RECORDER_H_ */