#include "renderer/rl_renderer.h"

RLRenderer::RLRenderer(Movement *movement) {}

void RLRenderer::Move(int command, int magnitude) {}

int RLRenderer::Render() {
  float thickness = 3.0f;
  Vector2 start = {55.0f, 55.0f};
  Vector2 end = {100.0f, 100.0f};
  Vector2 start2 = {100.0f, 100.0f};
  Vector2 end2 = {100.0f, 200.0f};
  BeginDrawingWrapper();
  ClearBackgroundWrapper(WHITE);
  DrawTextWrapper("Congrats! You created your first window!", 190, 200, 20,
                  LIGHTGRAY);
  DrawLineExWrapper(start, end, thickness, RED);
  DrawLineExWrapper(start2, end2, thickness, RED);

  EndDrawingWrapper();
  return 0;
}
