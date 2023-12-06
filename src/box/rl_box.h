#ifndef RL_BOX_H_
#define RL_BOX_H_

#include "box/box.h"
#include "raylib_wrapper/raylib_wrapper.h"
#include "window/rl_window.h"

constexpr int border_pixel_width = 5;

class RLBox : public Box {
 private:
  void CreateBox() const;
  RenderTexture2D box_screen;
  int x_safe_zone;
  int y_safe_zone;
  RLWindow* window;

  void DrawTitle() const;
  void DrawBorder() const;

 public:
  RLBox(RLWindow* window);
  ~RLBox() override = default;

  int GetXSafeZone() const override { return x_safe_zone; }
  int GetYSafeZone() const override { return y_safe_zone; }
  RenderTexture2D GetBoxScreen() const { return box_screen; }
};

#endif /* RL_BOX_H_ */