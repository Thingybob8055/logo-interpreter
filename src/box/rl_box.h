#ifndef RL_BOX_H_
#define RL_BOX_H_

#include "box/box.h"
#include "raylib_wrapper/raylib_wrapper.h"
#include "window/rl_window.h"

constexpr int border_pixel_width = 5;

// create a seperate screen for the box to be drawn on
class RLBox : public Box {
 private:
  void CreateBox() const;
  RenderTexture2D BoxScreen = LoadRenderTextureWrapper(screen_width, screen_height);

 public:
  explicit RLBox();
  ~RLBox() override = default;

  int GetXSafeZone() const override { return 0; }
  int GetYSafeZone() const override { return 0; }
};

#endif /* RL_BOX_H_ */