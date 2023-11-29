#include "renderer/rl_renderer.h"

RLRenderer::RLRenderer(Movement *movement) {}

void RLRenderer::Move(int command, int magnitude) {}

int RLRenderer::Render() {
  float thickness = 3.0f;
  Vector2 start = {0.0f, 0.0f};
  Vector2 end = {55.0f, 55.0f};
  Vector2 start2 = {55.0f, 55.0f};
  Vector2 end2 = {55.0f, 100.0f};

  BeginTextureModeWrapper(draw_screen);
  ClearBackgroundWrapper(RED);
  DrawTextWrapper("Congrats! You created your first window!", 190, 200, 20,
                  LIGHTGRAY);
  DrawLineExWrapper(start, end, thickness, GREEN);
  DrawLineExWrapper(start2, end2, thickness, GREEN);
  EndTextureModeWrapper();

  BeginDrawingWrapper();
  //start drawing the texture insde the box borders
  DrawTextureProWrapper(draw_screen.texture,
                 (Rectangle){0, 0, (float)draw_screen.texture.width,
                             -(float)draw_screen.texture.height},
                 (Rectangle){55, 55, (float)draw_screen.texture.width,
                             (float)draw_screen.texture.height},
                 (Vector2){0, 0}, 0.0f, WHITE);
  EndDrawingWrapper();
  return 0;
}
