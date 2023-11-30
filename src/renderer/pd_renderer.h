#ifndef PD_RENDERER_H_
#define PD_RENDERER_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "box/pd_box.h"
#include "movement/pd_movement.h"
#include "renderer/renderer.h"

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
  PDBox *current_box;

  PDMovement *movement;

 public:
  PDRenderer(PDBox *box, PDMovement *movement);

  void Move(int command, int magnitude) override;
  int Render() override;

  int GetXLocationFromMovement() const { return movement->GetXLocation(); }
  int GetYLocationFromMovement() const { return movement->GetYLocation(); }
  PenPosition GetPenPositionFromMovement() const {
    return movement->GetPenPosition();
  }

  PDBox *GetBox() { return current_box; }
  PDMovement *GetMovement() { return movement; }
};

#endif /* PD_RENDERER_H_ */