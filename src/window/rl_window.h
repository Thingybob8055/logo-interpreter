#ifndef RL_WINDOW_H_
#define RL_WINDOW_H_

#include "raylib_wrapper/raylib_wrapper.h"
#include "window/window.h"

constexpr int border_offset = 55;
constexpr int border_width = 950;
constexpr int border_height = 650;
constexpr int screen_width = (2 * border_offset + border_width);
constexpr int screen_height = (2 * border_offset + border_height);
constexpr const char* window_title = "Logo Interpreter";
constexpr int frames_per_second = 60;

class RLWindow : public Window {
 public:
  RLWindow();
  ~RLWindow() override;
  int GetInput() override;
};

#endif /* RL_WINDOW_H_ */