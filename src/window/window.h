#ifndef WINDOW_H_
#define WINDOW_H_

class Window {
 public:
  virtual bool ShouldExit() = 0;
  virtual ~Window() = default;
};

#endif /* WINDOW_H_ */
