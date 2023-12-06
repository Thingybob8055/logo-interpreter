#ifndef RL_WINDOW_H_
#define RL_WINDOW_H_

#include "raylib_wrapper/raylib_wrapper.h"
#include "window/window.h"

class RLWindow : public Window {
 private:
  int border_offset = 55;
  int border_width = 950;
  int border_height = 650;
  int screen_width = (2 * border_offset + border_width);
  int screen_height = (2 * border_offset + border_height);
  const char* window_title = "Logo Interpreter";
  int frames_per_second = 60;

 public:
  RLWindow();
  ~RLWindow() override;
  int GetYMaxScreenCoordinate() const override { return screen_height; }
  int GetXMaxScreenCoordinate() const override { return screen_width; }
  int GetBorderOffset() const { return border_offset; }
  int GetBorderWidth() const { return border_width; }
  int GetBorderHeight() const { return border_height; }
  bool ShouldExit() override;
};

#endif /* RL_WINDOW_H_ */