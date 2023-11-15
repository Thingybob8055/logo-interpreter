#ifndef PD_RENDERER_H_
#define PD_RENDERER_H_
#include "movement/movement.h"
#include "window/pd_window.h"

#define KEY_SPACE 32

class PDRenderer {
 private:
  int x_safe_zone;
  int y_safe_zone;
  PDWindow *current_window;

  // create instance of Movement
  Movement *movement;

 public:
  PDRenderer(PDWindow *window, int start_y_coordinate, int start_x_coordinate);

  void Move(int command);
  int Render();

  int GetXLocationFromMovement() { return movement->GetXLocation(); }
  int GetYLocationFromMovement() { return movement->GetYLocation(); }
  int GetXSafeZone() { return x_safe_zone; }
  int GetYSafeZone() { return y_safe_zone; }
  PenPosition GetPenPositionFromMovement() {
    return movement->GetPenPosition();
  }
  char *GetLeadingCharacterFromMovement() {
    return movement->GetLeadingCharacter();
  }
  char *GetTrailingCharacterFromMovement() {
    return movement->GetTrailingCharacter();
  }
};

#endif /* PD_RENDERER_H_ */