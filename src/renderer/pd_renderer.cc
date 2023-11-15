#include "pd_renderer.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

PDRenderer::PDRenderer(PDWindow *window, int start_y_coordinate,
                       int start_x_coordinate, char *leading_character, int starting_direction, PenPosition default_pen_position) {
  int y_max_screen_coordinate;
  int x_max_screen_coordinate;
  this->current_window = window;
  this->x_location = start_x_coordinate;
  this->y_location = start_y_coordinate;
  getmaxyx(this->current_window->GetWindow(), y_max_screen_coordinate,
           x_max_screen_coordinate);
  this->x_safe_zone = x_max_screen_coordinate - 2;
  this->y_safe_zone = y_max_screen_coordinate - 2;
  keypad(this->current_window->GetWindow(), true);
  this->leading_character = leading_character;
  this->trailing_character = (char *)"";
  this->last_command = starting_direction;
  this->pen_position = default_pen_position;
}

void PDRenderer::Move(int command) {
  switch (command) {
  case KEY_UP:
    MoveUp();
    break;
  case KEY_DOWN:
    MoveDown();
    break;
  case KEY_LEFT:
    MoveLeft();
    break;
  case KEY_RIGHT:
    MoveRight();
    break;
  case KEY_SPACE:
    if (this->pen_position == PEN_DOWN) {
      this->pen_position = PEN_UP;
    } else {
      this->pen_position = PEN_DOWN;
    }
    break;
  default:
    break;
  }
}

int PDRenderer::Render() {
  int return_value = OK;
  WINDOW *window = this->current_window->GetWindow();
  if (this->last_command == KEY_UP) {
    return_value |= mvwaddstr(window, this->y_location + 1, this->x_location,
                              this->trailing_character);
  } else if (this->last_command == KEY_LEFT) {
    return_value |= mvwaddstr(window, this->y_location, this->x_location + 1,
                              this->trailing_character);
  } else if (this->last_command == KEY_DOWN) {
    return_value |= mvwaddstr(window, this->y_location - 1, this->x_location,
                              this->trailing_character);
  } else if (this->last_command == KEY_RIGHT) {
    return_value |= mvwaddstr(window, this->y_location, this->x_location - 1,
                              this->trailing_character);
  }
  return_value |= mvwaddstr(window, this->y_location, this->x_location,
                            this->leading_character);
  return_value |= wrefresh(window);
  return return_value;
}

void PDRenderer::MoveUp() {
  this->leading_character = (char *)"▲";
  SetTrailingCharacter(KEY_UP);
  this->last_command = KEY_UP;
  this->y_location--;
  BoundaryCheck();
}

void PDRenderer::MoveDown() {
  this->leading_character = (char *)"▼";
  SetTrailingCharacter(KEY_DOWN);
  this->last_command = KEY_DOWN;
  this->y_location++;
  BoundaryCheck();
}

void PDRenderer::MoveLeft() {
  this->leading_character = (char *)"◀";
  SetTrailingCharacter(KEY_LEFT);
  this->last_command = KEY_LEFT;
  this->x_location--;
  BoundaryCheck();
}

void PDRenderer::MoveRight() {
  this->leading_character = (char *)"▶";
  SetTrailingCharacter(KEY_RIGHT);
  this->last_command = KEY_RIGHT;
  this->x_location++;
  BoundaryCheck();
}

const char *PDRenderer::TrailingCharacter(int current_command) {
  if (current_command == KEY_DOWN) {
    if (this->last_command == KEY_RIGHT) {
      return "┐";
    } else if (this->last_command == KEY_LEFT) {
      return "┌";
    } else {
      return "│";
    }
  }

  if (current_command == KEY_UP) {
    if (this->last_command == KEY_RIGHT) {
      return "┘";
    } else if (this->last_command == KEY_LEFT) {
      return "└";
    } else {
      return "│";
    }
  }

  if (current_command == KEY_LEFT) {
    if (this->last_command == KEY_UP) {
      return "┐";
    } else if (this->last_command == KEY_DOWN) {
      return "┘";
    } else {
      return "─";
    }
  }

  if (current_command == KEY_RIGHT) {
    if (this->last_command == KEY_UP) {
      return "┌";
    } else if (this->last_command == KEY_DOWN) {
      return "└";
    } else {
      return "─";
    }
  }
  return " ";
}

void PDRenderer::SetTrailingCharacter(int current_command) {
  if (this->pen_position == PEN_DOWN) {
    this->trailing_character = (char *)TrailingCharacter(current_command);
  } else {
    this->trailing_character = (char *)" ";
  }
}

void PDRenderer::BoundaryCheck() {
  static uint8_t ceiling_cap = 1;
  if (this->y_location < ceiling_cap) {
    this->y_location = ceiling_cap;
  } else if (this->y_location > this->y_safe_zone) {
    this->y_location = this->y_safe_zone;
  } else if (this->x_location < ceiling_cap) {
    this->x_location = ceiling_cap;
  } else if (this->x_location > this->x_safe_zone) {
    this->x_location = this->x_safe_zone;
  }
}
