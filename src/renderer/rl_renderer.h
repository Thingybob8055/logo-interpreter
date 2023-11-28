#ifndef RL_RENDERER_H_
#define RL_RENDERER_H_

#include "movement/movement.h"
#include "raylib_wrapper/raylib_wrapper.h"
#include "renderer/renderer.h"

class RLRenderer : public Renderer {
 public:
  explicit RLRenderer(Movement *movement);

  void Move(int command, int magnitude) override;
  int Render() override;
};

#endif /* RL_RENDERER_H_ */
