#include "renderer/rl_renderer.h"

RLRenderer::RLRenderer(RLBox *box, Movement *movement) : current_box(box) {
  this->InitialiseTextures();
  draw_screen = LoadRenderTextureWrapper(current_box->GetXSafeZone(),
                                         current_box->GetYSafeZone());
}

void RLRenderer::Move(int command, int magnitude) {}

int RLRenderer::Render() {
  BeginTextureModeWrapper(draw_screen);
  ClearBackgroundWrapper(BLUE);
  Rectangle source =
      (Rectangle){0, 0, (float)turtle.width, (float)turtle.height};
  Rectangle dest = (Rectangle){(float)current_box->GetXSafeZone() / 2,
                               (float)current_box->GetYSafeZone() / 2,
                               turtle_texture_width, turtle_texture_height};
  DrawTextureProWrapper(turtle, source, dest,
                 (Vector2){dest.width / 2, dest.height / 2}, 270.0f, WHITE);
  EndTextureModeWrapper();

  BeginDrawingWrapper();
  DrawTextureProWrapper(
      current_box->GetBoxScreen().texture,
      (Rectangle){0, 0, (float)current_box->GetBoxScreen().texture.width,
                  -(float)current_box->GetBoxScreen().texture.height},
      (Rectangle){0, 0, (float)current_box->GetBoxScreen().texture.width,
                  (float)current_box->GetBoxScreen().texture.height},
      (Vector2){0, 0}, 0.0f, WHITE);
  // start drawing the texture insde the box borders
  DrawTextureProWrapper(draw_screen.texture,
                        (Rectangle){0, 0, (float)draw_screen.texture.width,
                                    -(float)draw_screen.texture.height},
                        (Rectangle){55, 55, (float)draw_screen.texture.width,
                                    (float)draw_screen.texture.height},
                        (Vector2){0, 0}, 0.0f, WHITE);
  EndDrawingWrapper();
  return 0;
}

void RLRenderer::InitialiseTextures() {
  turtle = LoadTextureWrapper("resouces/turtle.png");
  float scale_factor = 0.04f;
  turtle_texture_width = turtle.width * scale_factor;
  turtle_texture_height = turtle.height * scale_factor;
}