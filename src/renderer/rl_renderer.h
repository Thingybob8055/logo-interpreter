#ifndef RL_RENDERER_H_
#define RL_RENDERER_H_

#include "box/rl_box.h"
#include "movement/rl_movement.h"
#include "raylib_wrapper/raylib_wrapper.h"
#include "renderer/renderer.h"

class RLRenderer : public Renderer {
 public:
  RLRenderer(RLBox *box, RLMovement *movement);

  void Move(int command, int magnitude) override;
  int Render() override;
  RLBox *GetBox() const { return current_box; }

 private:
  RenderTexture2D draw_screen;
  RLBox *current_box;
  Texture2D turtle;

  float turtle_texture_width;
  float turtle_texture_height;

  std::vector<TrailPoint> trail_points;

  RLMovement *movement;

  void InitialiseTextures();
  void MoveForwardsWithMagnitude(int magnitude);
  void MoveBackwardsWithMagnitude(int magnitude);
  void TogglePenPosition();
};

#endif /* RL_RENDERER_H_ */
