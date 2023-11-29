#include "rl_box.h"

void DrawTitle();
void DrawBorder();

RLBox::RLBox() { this->CreateBox(); }

void RLBox::CreateBox() const {
  BeginTextureModeWrapper(BoxScreen);
  ClearBackgroundWrapper(WHITE);
  DrawBorder();
  DrawTitle();
  EndTextureModeWrapper();
}

void DrawTitle() {
  int text_pos_x = border_offset - 5;
  int text_pos_y = 5;
  int text_size = 40;
  DrawTextWrapper("Logo Interpreter", text_pos_x, text_pos_y, text_size, BLACK);
}

void DrawBorder() {
  DrawRectangleLinesExWrapper(
      Rectangle{(float)border_offset - border_pixel_width,
                (float)border_offset - border_pixel_width,
                (float)border_width + 10, (float)border_height + 10},
      border_pixel_width, BLACK);
}