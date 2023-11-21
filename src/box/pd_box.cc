#include "pd_box.h"

PDBox::PDBox(PDWindow* window)
    : window(window), box_x_character(0), box_y_character(0) {
  CreateBox(window->GetWindow(), box_y_character, box_x_character);
}

void PDBox::CreateBox(WINDOW* window, int box_y_character,
                      int box_x_character) {
  box(window, box_y_character, box_x_character);
  refresh();
  wrefresh(window);
  int x_max_coordinate;
  int y_max_coordinate;
  getmaxyx(window, y_max_coordinate, x_max_coordinate);
  this->x_safe_zone = x_max_coordinate - 2;
  this->y_safe_zone = y_max_coordinate - 2;
}