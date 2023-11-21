#include "pd_window.h"

#include <iostream>

PDWindow::PDWindow(int argc, char **argv) {
  InitXcurses(argc, argv);
  int y_max_coordinate;
  int x_max_coordinate;
  getmaxyx(stdscr, y_max_coordinate, x_max_coordinate);

  int y_screen_safe_zone = y_max_coordinate - 1;
  int x_screen_safe_zone = x_max_coordinate - 2;

  int begin_y = 1;
  int begin_x = 1;
  this->window =
      newwin(y_screen_safe_zone, x_screen_safe_zone, begin_y, begin_x);
  this->x_max_screen_coordinate = x_max_coordinate;
  this->y_max_screen_coordinate = y_max_coordinate;
}

WINDOW *PDWindow::GetWindow() { return window; }

void InitXcurses(int argc, char **argv) {
#ifdef XCURSES
  Xinitscr(argc, argv);
#else
  initscr();
#endif
  noecho();
  cbreak();
  curs_set(0);
}