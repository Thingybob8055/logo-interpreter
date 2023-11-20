#include "pd_renderer.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

PDRenderer::PDRenderer(PDWindow *window, Movement *movement) {
  this->current_window = window;
  keypad(this->current_window->GetWindow(), true);
  this->movement = movement;
}

void PDRenderer::Move(int command, int magnitude) {
  if (this->movement->GetCurrentHeadingFromAssembler() == HEADING_RIGHT ||
      this->movement->GetCurrentHeadingFromAssembler() == HEADING_LEFT) {
    magnitude *= 2;
  }
  switch (command) {
    case KEY_UP:
      for (int i = 0; i < magnitude; i++) {
        this->movement->MoveForward();
        this->Render();
      }
      break;
    case KEY_DOWN:
      for (int i = 0; i < magnitude; i++) {
        this->movement->MoveBackward();
        this->Render();
      }
      break;
    case KEY_LEFT:
      this->movement->TurnLeft90();
      break;
    case KEY_RIGHT:
      this->movement->TurnRight90();
      break;
    case KEY_SPACE:
      if (this->movement->GetPenPosition() == PEN_DOWN) {
        this->movement->SetPenPosition(PEN_UP);
      } else {
        this->movement->SetPenPosition(PEN_DOWN);
      }
      break;
    default:
      break;
  }
}

int PDRenderer::Render() {
  int return_value = OK;
  WINDOW *window = this->current_window->GetWindow();
  Heading current_heading = this->movement->GetCurrentHeadingFromAssembler();
  Heading last_heading = this->movement->GetLastHeadingFromAssembler();
  Direction last_direction = this->movement->GetLastDirectionFronAssembler();
  int x_location = this->movement->GetXLocation();
  int y_location = this->movement->GetYLocation();
  char *trailing_character =
      this->movement->GetTrailingCharacterFromAssembler();

  if (last_direction == FORWARDS) {
    if (current_heading == HEADING_RIGHT && last_heading == HEADING_RIGHT) {
      return_value |=
          mvwaddstr(window, y_location, x_location - 1, trailing_character);
    } else if (current_heading == HEADING_LEFT &&
               last_heading == HEADING_LEFT) {
      return_value |=
          mvwaddstr(window, y_location, x_location + 1, trailing_character);
    } else if (current_heading == HEADING_UP && last_heading == HEADING_UP) {
      return_value |=
          mvwaddstr(window, y_location + 1, x_location, trailing_character);
    } else if (current_heading == HEADING_DOWN &&
               last_heading == HEADING_DOWN) {
      return_value |=
          mvwaddstr(window, y_location - 1, x_location, trailing_character);
    }
  } else if (last_direction == BACKWARDS) {
    if (current_heading == HEADING_RIGHT && last_heading == HEADING_RIGHT) {
      return_value |=
          mvwaddstr(window, y_location, x_location + 1, trailing_character);
    } else if (current_heading == HEADING_LEFT &&
               last_heading == HEADING_LEFT) {
      return_value |=
          mvwaddstr(window, y_location, x_location - 1, trailing_character);
    } else if (current_heading == HEADING_UP && last_heading == HEADING_UP) {
      return_value |=
          mvwaddstr(window, y_location - 1, x_location, trailing_character);
    } else if (current_heading == HEADING_DOWN &&
               last_heading == HEADING_DOWN) {
      return_value |=
          mvwaddstr(window, y_location + 1, x_location, trailing_character);
    }
  }

  return_value |= mvwaddstr(window, y_location, x_location,
                            this->movement->GetLeadingCharacterFromAssembler());
  return_value |= wrefresh(window);
  return return_value;
}