#ifndef RL_RENDERER_H_
#define RL_RENDERER_H_

#include "box/rl_box.h"
#include "movement/rl_movement.h"
#include "raylib_wrapper/raylib_wrapper.h"
#include "renderer/renderer.h"
#include "recorder/rl_recorder.h"

class RLRenderer : public Renderer {
 public:
  RLRenderer(RLBox *box, RLMovement *movement, RLRecorder *recorder);

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
  RLRecorder *recorder;

  void InitialiseTextures();
  void MoveForwardsWithMagnitude(int magnitude);
  void MoveBackwardsWithMagnitude(int magnitude);
  void TogglePenPosition();
  void RenderTurtle() const;
  void RenderTrail();
};

#endif /* RL_RENDERER_H_ */
