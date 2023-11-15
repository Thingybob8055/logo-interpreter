#ifndef PD_BOX_H_
#define PD_BOX_H_

#include "curses.h"
#include "window/pd_window.h"

class PDBox {
 private:
  int box_x_character;
  int box_y_character;
  int y_safe_zone;
  int x_safe_zone;
  PDWindow *window;

 public:
  void CreateBox();
  PDBox(PDWindow *window);
  int GetXSafeZone() { return x_safe_zone; }
  int GetYSafeZone() { return y_safe_zone; }
};

#endif /* PD_BOX_H_ */