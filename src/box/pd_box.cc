#include "pd_box.h"

PDBox::PDBox(PDWindow* window) {
  this->box_x_character = 0;
  this->box_y_character = 0;
  this->window = window;
}

void PDBox::CreateBox() {
  box(window->GetWindow(), box_y_character, box_x_character);
  refresh();
  wrefresh(window->GetWindow());
  int x_max_coordinate;
  int y_max_coordinate;
  getmaxyx(window->GetWindow(), y_max_coordinate, x_max_coordinate);
  this->x_safe_zone = x_max_coordinate - 2;
  this->y_safe_zone = y_max_coordinate - 2;
}