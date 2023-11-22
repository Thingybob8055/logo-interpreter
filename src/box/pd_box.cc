#include "pd_box.h"

PDBox::PDBox(PDWindow* pd_window) : pd_window(pd_window) {
  CreateBox(pd_window->GetWindow(), box_y_character, box_x_character);
}

void PDBox::CreateBox(WINDOW* window, int y_character, int x_character) {
  box(window, y_character, x_character);
  int x_max_coordinate;
  int y_max_coordinate;
  getmaxyx(window, y_max_coordinate, x_max_coordinate);
  this->x_safe_zone = x_max_coordinate - 2;
  this->y_safe_zone = y_max_coordinate - 2;
}