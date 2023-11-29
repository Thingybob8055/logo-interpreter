#include "pd_renderer.h"

#include "keys.h"

PDRenderer::PDRenderer(PDBox *box, Movement *movement)
    : current_box(box), movement(movement) {
  keypad(this->current_box->GetWindow(), true);
}

void PDRenderer::Move(int command, int magnitude) {
  magnitude = this->GetMagnitudeForHeading(
      this->movement->GetCurrentHeadingFromAssembler(), magnitude);
  switch (command) {
    case KEY_UP:
      this->MoveWithDirectionAndMagnitude(FORWARDS, magnitude);
      break;
    case KEY_DOWN:
      this->MoveWithDirectionAndMagnitude(BACKWARDS, magnitude);
      break;
    case KEY_LEFT:
      this->movement->TurnLeft90();
      break;
    case KEY_RIGHT:
      this->movement->TurnRight90();
      break;
    case KEY_SPACE:
      this->TogglePenPosition();
      break;
    default:
      break;
  }
}

int PDRenderer::Render() {
  int return_value = OK;
  WINDOW *window = this->current_box->GetWindow();
  Heading current_heading = this->movement->GetCurrentHeadingFromAssembler();
  Heading last_heading = this->movement->GetLastHeadingFromAssembler();
  Direction last_direction = this->movement->GetLastDirectionFronAssembler();
  int x_location = this->movement->GetXLocation();
  int y_location = this->movement->GetYLocation();
  const char *trailing_character =
      this->movement->GetTrailingCharacterFromAssembler();
  const char *leading_character =
      this->movement->GetLeadingCharacterFromAssembler();

  if (last_direction == FORWARDS) {
    return_value |= this->RenderTrailingCharacterForwardsMovement(
        window, y_location, x_location, trailing_character, current_heading,
        last_heading);
  } else if (last_direction == BACKWARDS) {
    return_value |= this->RenderTrailingCharacterBackwardsMovement(
        window, y_location, x_location, trailing_character, current_heading,
        last_heading);
  }

  return_value |= this->RenderLeadingCharacter(window, y_location, x_location,
                                               leading_character);
  return return_value;
}

void PDRenderer::TogglePenPosition() {
  if (this->movement->GetPenPosition() == PEN_DOWN) {
    this->movement->SetPenPosition(PEN_UP);
  } else {
    this->movement->SetPenPosition(PEN_DOWN);
  }
}

void PDRenderer::MoveWithDirectionAndMagnitude(Direction direction,
                                               int magnitude) {
  if (direction == FORWARDS) {
    for (int i = 0; i < magnitude; i++) {
      this->movement->MoveForward();
      this->Render();
    }
  } else if (direction == BACKWARDS) {
    for (int i = 0; i < magnitude; i++) {
      this->movement->MoveBackward();
      this->Render();
    }
  }
}

int PDRenderer::GetMagnitudeForHeading(Heading heading, int magnitude) const {
  if (heading == HEADING_RIGHT || heading == HEADING_LEFT) {
    magnitude *= 2;
  }
  return magnitude;
}

int PDRenderer::RenderTrailingCharacterForwardsMovement(
    WINDOW *window, int y_location, int x_location,
    const char *trailing_character, Heading current_heading,
    Heading last_heading) const {
  int return_value = OK;
  if (current_heading == HEADING_RIGHT && last_heading == HEADING_RIGHT) {
    return_value |=
        mvwaddstr(window, y_location, x_location - 1, trailing_character);
  } else if (current_heading == HEADING_LEFT && last_heading == HEADING_LEFT) {
    return_value |=
        mvwaddstr(window, y_location, x_location + 1, trailing_character);
  } else if (current_heading == HEADING_UP && last_heading == HEADING_UP) {
    return_value |=
        mvwaddstr(window, y_location + 1, x_location, trailing_character);
  } else if (current_heading == HEADING_DOWN && last_heading == HEADING_DOWN) {
    return_value |=
        mvwaddstr(window, y_location - 1, x_location, trailing_character);
  }
  return return_value;
}

int PDRenderer::RenderTrailingCharacterBackwardsMovement(
    WINDOW *window, int y_location, int x_location,
    const char *trailing_character, Heading current_heading,
    Heading last_heading) const {
  int return_value = OK;
  if (current_heading == HEADING_RIGHT && last_heading == HEADING_RIGHT) {
    return_value |=
        mvwaddstr(window, y_location, x_location + 1, trailing_character);
  } else if (current_heading == HEADING_LEFT && last_heading == HEADING_LEFT) {
    return_value |=
        mvwaddstr(window, y_location, x_location - 1, trailing_character);
  } else if (current_heading == HEADING_UP && last_heading == HEADING_UP) {
    return_value |=
        mvwaddstr(window, y_location - 1, x_location, trailing_character);
  } else if (current_heading == HEADING_DOWN && last_heading == HEADING_DOWN) {
    return_value |=
        mvwaddstr(window, y_location + 1, x_location, trailing_character);
  }
  return return_value;
}

int PDRenderer::RenderLeadingCharacter(WINDOW *window, int y_location,
                                       int x_location,
                                       const char *leading_character) const {
  int return_value = OK;
  return_value = mvwaddstr(window, y_location, x_location, leading_character);
  return return_value;
}