#include "movement.h"

#include <curses.h>

#include <cstdint>

Movement::Movement() {}

Movement::Movement(int x_location, int y_location, int x_safe_zone,
                   int y_safe_zone) {
  this->x_location = x_location;
  this->y_location = y_location;
  this->x_safe_zone = x_safe_zone;
  this->y_safe_zone = y_safe_zone;
  this->last_command = KEY_RIGHT;
  this->pen_position = PEN_DOWN;
  this->leading_character = (char *)"▶";
  this->trailing_character = (char *)"";
}

void Movement::BoundaryCheck() {
  static uint8_t ceiling_cap = 1;
  if (y_location < ceiling_cap) {
    y_location = ceiling_cap;
  } else if (y_location > y_safe_zone) {
    y_location = y_safe_zone;
  } else if (x_location < ceiling_cap) {
    x_location = ceiling_cap;
  } else if (x_location > x_safe_zone) {
    x_location = x_safe_zone;
  }
}

void Movement::MoveUp() {
  leading_character = (char *)"▲";
  SetTrailingCharacter(KEY_UP);
  last_command = KEY_UP;
  y_location--;
  BoundaryCheck();
}

void Movement::MoveDown() {
  leading_character = (char *)"▼";
  SetTrailingCharacter(KEY_DOWN);
  last_command = KEY_DOWN;
  y_location++;
  BoundaryCheck();
}

void Movement::MoveLeft() {
  leading_character = (char *)"◀";
  SetTrailingCharacter(KEY_LEFT);
  last_command = KEY_LEFT;
  x_location--;
  BoundaryCheck();
}

void Movement::MoveRight() {
  leading_character = (char *)"▶";
  SetTrailingCharacter(KEY_RIGHT);
  last_command = KEY_RIGHT;
  x_location++;
  BoundaryCheck();
}

const char *Movement::TrailingCharacter(int current_command) {
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

void Movement::SetTrailingCharacter(int current_command) {
  if (this->pen_position == PEN_DOWN) {
    this->trailing_character = (char *)TrailingCharacter(current_command);
  } else {
    this->trailing_character = (char *)" ";
  }
}