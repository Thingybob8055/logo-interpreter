#ifndef PD_WINDOW_H_
#define PD_WINDOW_H_

#include <curses.h>

#include <cstdint>

class PDWindow {
 private:
  WINDOW *window;
  int y_max_screen_coordinate;
  int x_max_screen_coordinate;

 public:
  PDWindow(int argc, char **argv);

  WINDOW *GetWindow();
  int GetYMaxScreenCoordinate() const { return y_max_screen_coordinate; }
  int GetXMaxScreenCoordinate() const { return x_max_screen_coordinate; }
};

void InitXcurses(int argc, char **argv);

#endif /* PD_WINDOW_H_ */
