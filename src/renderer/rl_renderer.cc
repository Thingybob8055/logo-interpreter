#include "renderer/rl_renderer.h"

#include <unistd.h>

#include "curses.h"

RLRenderer::RLRenderer(RLBox *box, RLMovement *movement)
    : current_box(box), movement(movement) {
  this->InitialiseTextures();
  draw_screen = LoadRenderTextureWrapper(current_box->GetXSafeZone(),
                                         current_box->GetYSafeZone());
}

void RLRenderer::Move(int command, int magnitude) {
  switch (command) {
    case KEY_UP:
      MoveForwardsWithMagnitude(magnitude);
      break;
    case KEY_DOWN:
      MoveBackwardsWithMagnitude(magnitude);
      break;
    case KEY_LEFT:
      movement->TurnLeft90();
      break;
    case KEY_RIGHT:
      movement->TurnRight90();
      break;
    case 32:
      TogglePenPosition();
      break;
    default:
      break;
  }
}

int RLRenderer::Render() {
  trail_points = movement->GetTrailPoints();
  BeginTextureModeWrapper(draw_screen);
  ClearBackgroundWrapper(WHITE);
  Rectangle source =
      (Rectangle){0, 0, (float)turtle.width, (float)turtle.height};
  Rectangle dest = (Rectangle){(float)movement->GetXLocation(),
                               (float)movement->GetYLocation(),
                               turtle_texture_width, turtle_texture_height};
  DrawTextureProWrapper(turtle, source, dest,
                        (Vector2){dest.width / 2, dest.height / 2},
                        (float)movement->GetAngle(), WHITE);

  for (size_t i = 1; i < trail_points.size(); ++i) {
    DrawRectangleVWrapper(trail_points[i - 1].position, {2.0f, 2.0f},
                          trail_points[i].color);
  }

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

void RLRenderer::MoveForwardsWithMagnitude(int magnitude) {
  for (int i = 0; i < magnitude; i++) {
    this->movement->MoveForward();
  }
}

void RLRenderer::MoveBackwardsWithMagnitude(int magnitude) {
  for (int i = 0; i < magnitude; i++) {
    this->movement->MoveBackward();
  }
}

void RLRenderer::TogglePenPosition() {
  if (movement->GetPenPosition() == PEN_UP) {
    movement->SetPenPosition(PEN_DOWN);
  } else {
    movement->SetPenPosition(PEN_UP);
  }
}