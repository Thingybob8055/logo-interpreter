#ifndef RL_RENDERER_H_
#define RL_RENDERER_H_

#include "box/rl_box.h"
#include "movement/movement.h"
#include "raylib_wrapper/raylib_wrapper.h"
#include "renderer/renderer.h"

class RLRenderer : public Renderer {
 public:
  RLRenderer(RLBox *box, Movement *movement);

  void Move(int command, int magnitude) override;
  int Render() override;
  RLBox *GetBox() const { return current_box; }

 private:
  RenderTexture2D draw_screen = LoadRenderTextureWrapper(950, 650);
  RLBox *current_box;
};

#endif /* RL_RENDERER_H_ */
