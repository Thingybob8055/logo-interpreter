#ifndef PD_RENDERER_H_
#define PD_RENDERER_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "keys.h"
#include "movement/movement.h"
#include "renderer/renderer.h"
#include "window/pd_window.h"

class PDRenderer : public Renderer {
 private:
  void TogglePenPosition();
  void MoveWithDirectionAndMagnitude(Direction direction, int magnitude);
  int GetMagnitudeForHeading(Heading heading, int magnitude) const;
  int RenderTrailingCharacterForwardsMovement(WINDOW *window, int y_location,
                                              int x_location,
                                              const char *trailing_character,
                                              Heading current_heading,
                                              Heading last_heading) const;
  int RenderTrailingCharacterBackwardsMovement(WINDOW *window, int y_location,
                                               int x_location,
                                               const char *trailing_character,
                                               Heading current_heading,
                                               Heading last_heading) const;
  int RenderLeadingCharacter(WINDOW *window, int y_location, int x_location,
                             const char *leading_character) const;
  PDWindow *current_window;

  Movement *movement;

 public:
  PDRenderer(PDWindow *window, Movement *movement);

  void Move(int command, int magnitude) override;
  int Render() override;

  int GetXLocationFromMovement() const { return movement->GetXLocation(); }
  int GetYLocationFromMovement() const { return movement->GetYLocation(); }
  PenPosition GetPenPositionFromMovement() const {
    return movement->GetPenPosition();
  }

  PDWindow *GetWindow() { return current_window; }
  Movement *GetMovement() { return movement; }
};

#endif /* PD_RENDERER_H_ */