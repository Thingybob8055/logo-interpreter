#include "rl_box.h"

void DrawTitle();
void DrawBorder();

RLBox::RLBox(RLWindow* window)
    : x_safe_zone(window->GetBorderWidth()),
      y_safe_zone(window->GetBorderHeight()),
      window(window) {
  box_screen = LoadRenderTextureWrapper(window->GetXMaxScreenCoordinate(),
                                        window->GetYMaxScreenCoordinate());
  this->CreateBox();
}

void RLBox::CreateBox() const {
  BeginTextureModeWrapper(box_screen);
  ClearBackgroundWrapper(WHITE);
  DrawBorder();
  DrawTitle();
  EndTextureModeWrapper();
}

void RLBox::DrawTitle() const {
  int text_pos_x = window->GetBorderOffset() - 5;
  int text_pos_y = 5;
  int text_size = 40;
  DrawTextWrapper("Logo Interpreter", text_pos_x, text_pos_y, text_size, BLACK);
}

void RLBox::DrawBorder() const {
  DrawRectangleLinesExWrapper(
      Rectangle{(float)window->GetBorderOffset() - border_pixel_width,
                (float)window->GetBorderOffset() - border_pixel_width,
                (float)x_safe_zone + 10, (float)y_safe_zone + 10},
      border_pixel_width, BLACK);
}