#include "recorder/recorder.h"

class NoopRecorder : public Recorder {
 public:
  void InitRecording() override { return; }
  void StartRecording() override { return; }
  void SaveRecording() override { return; }
  void SaveScreenshot() override { return; }
};
