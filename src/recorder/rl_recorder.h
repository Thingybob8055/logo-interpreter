#ifndef RL_RECORDER_H_
#define RL_RECORDER_H_

#include <raylib_wrapper/raylib_wrapper.h>
#include "window/rl_window.h"
#include "recorder.h"
#include "external/msf_gif.h"

class RLRecorder : public Recorder {
 public:
  RLRecorder();

  void InitRecording() override;
  void StartRecording() override;
  void SaveRecording() override;

 private:
  int gifFrameCounter = 0;  
  bool gifRecording = false; 
  MsfGifState gifState = {0};
};

#endif /* RL_RECORDER_H_ */