#ifndef WINDOW_H_
#define WINDOW_H_

class Window {
 public:
  virtual int GetInput() = 0;
  virtual ~Window() = default;
};

#endif /* WINDOW_H_ */
