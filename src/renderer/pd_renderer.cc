#include "pd_renderer.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

PDRenderer::PDRenderer(PDWindow *window, int start_y_coordinate,
                       int start_x_coordinate) {
  int y_max_screen_coordinate;
  int x_max_screen_coordinate;
  this->current_window = window;

  getmaxyx(this->current_window->GetWindow(), y_max_screen_coordinate,
           x_max_screen_coordinate);
  this->x_safe_zone = x_max_screen_coordinate - 2;
  this->y_safe_zone = y_max_screen_coordinate - 2;
  keypad(this->current_window->GetWindow(), true);
  this->movement = new Movement(start_x_coordinate, start_y_coordinate,
                                this->x_safe_zone, this->y_safe_zone);
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
  if (this->movement->GetLastCommand() == KEY_UP) {
    return_value |= mvwaddstr(window, movement->GetYLocation() + 1,
                              movement->GetXLocation(),
                              this->movement->GetTrailingCharacter());
  } else if (this->movement->GetLastCommand() == KEY_LEFT) {
    return_value |= mvwaddstr(window, movement->GetYLocation(),
                              movement->GetXLocation() + 1,
                              this->movement->GetTrailingCharacter());
  } else if (this->movement->GetLastCommand() == KEY_DOWN) {
    return_value |= mvwaddstr(window, movement->GetYLocation() - 1,
                              movement->GetXLocation(),
                              this->movement->GetTrailingCharacter());
  } else if (this->movement->GetLastCommand() == KEY_RIGHT) {
    return_value |= mvwaddstr(window, movement->GetYLocation(),
                              movement->GetXLocation() - 1,
                              this->movement->GetTrailingCharacter());
  }
  return_value |=
      mvwaddstr(window, movement->GetYLocation(), movement->GetXLocation(),
                this->movement->GetLeadingCharacter());
  return_value |= wrefresh(window);
  return return_value;
}