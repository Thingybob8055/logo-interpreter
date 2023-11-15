#include "pd_window.h"

PDWindow::PDWindow(int argc, char **argv) {
#ifdef XCURSES
  Xinitscr(argc, argv);
#else
  initscr();
#endif
  noecho();
  cbreak();
  curs_set(0);
  getmaxyx(stdscr, y_max_screen_coordinate, x_max_screen_coordinate);

  uint8_t y_safe_zone = (uint8_t)(y_max_screen_coordinate - 1);
  uint8_t x_safe_zone = (uint8_t)(x_max_screen_coordinate - 2);
  uint8_t begin_y = 1;
  uint8_t begin_x = 1;
  uint8_t box_x_character = 0;
  uint8_t box_y_character = 0;
  this->window = newwin(y_safe_zone, x_safe_zone, begin_y, begin_x);
  // Create drwaing zone
  box(this->window, box_y_character, box_x_character);
  refresh();
  wrefresh(window);
}

PDWindow::~PDWindow() {}

WINDOW *PDWindow::GetWindow() { return window; }
