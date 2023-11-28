#include "pd_window.h"

PDWindow::PDWindow() {
  InitXcurses();
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

PDWindow::~PDWindow() { delwin(window); }

bool PDWindow::ShouldExit() { return wgetch(window) != 0; }

WINDOW *PDWindow::GetWindow() { return window; }

void InitXcurses() {
#ifdef XCURSES
  char *params[0];
  Xinitscr(0, params);
#else
  initscr();
#endif
  noecho();
  cbreak();
  curs_set(0);
}