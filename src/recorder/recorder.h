#ifndef RECORDING_H_
#define RECORDING_H_

class Recorder {
 public:
  virtual void InitRecording() = 0;
  virtual void StartRecording() = 0;
  virtual void SaveRecording() = 0;
  virtual void SaveScreenshot() = 0;
  virtual ~Recorder() = default;
};

#endif /* RECORDING_H_ */