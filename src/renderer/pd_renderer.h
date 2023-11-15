#ifndef PD_RENDERER_H_
#define PD_RENDERER_H_
#include "movement/movement.h"
#include "window/pd_window.h"

#define KEY_SPACE 32

class PDRenderer {
 private:
  PDWindow *current_window;

  // create instance of Movement
  Movement *movement;

 public:
  PDRenderer(PDWindow *window, Movement *movement);

  void Move(int command);
  int Render();

  int GetXLocationFromMovement() { return movement->GetXLocation(); }
  int GetYLocationFromMovement() { return movement->GetYLocation(); }
  PenPosition GetPenPositionFromMovement() {
    return movement->GetPenPosition();
  }

  PDWindow *GetWindow() { return current_window; }
  Movement *GetMovement() { return movement; }
};

#endif /* PD_RENDERER_H_ */