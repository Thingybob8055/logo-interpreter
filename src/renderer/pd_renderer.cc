#include "pd_renderer.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

PDRenderer::PDRenderer(PDWindow *window, Movement *movement) {
  this->current_window = window;
  keypad(this->current_window->GetWindow(), true);
  this->movement = movement;
}

void PDRenderer::Move(int command) {
  switch (command) {
    case KEY_UP:
      this->movement->MoveUp();
      break;
    case KEY_DOWN:
      this->movement->MoveDown();
      break;
    case KEY_LEFT:
      this->movement->MoveLeft();
      break;
    case KEY_RIGHT:
      this->movement->MoveRight();
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
  if (this->movement->GetLastCommandFromAssembler() == KEY_UP) {
    return_value |= mvwaddstr(
        window, movement->GetYLocation() + 1, movement->GetXLocation(),
        this->movement->GetTrailingCharacterFromAssembler());
  } else if (this->movement->GetLastCommandFromAssembler() == KEY_LEFT) {
    return_value |= mvwaddstr(
        window, movement->GetYLocation(), movement->GetXLocation() + 1,
        this->movement->GetTrailingCharacterFromAssembler());
  } else if (this->movement->GetLastCommandFromAssembler() == KEY_DOWN) {
    return_value |= mvwaddstr(
        window, movement->GetYLocation() - 1, movement->GetXLocation(),
        this->movement->GetTrailingCharacterFromAssembler());
  } else if (this->movement->GetLastCommandFromAssembler() == KEY_RIGHT) {
    return_value |= mvwaddstr(
        window, movement->GetYLocation(), movement->GetXLocation() - 1,
        this->movement->GetTrailingCharacterFromAssembler());
  }
  return_value |=
      mvwaddstr(window, movement->GetYLocation(), movement->GetXLocation(),
                this->movement->GetLeadingCharacterFromAssembler());
  return_value |= wrefresh(window);
  return return_value;
}