#include "rl_movement.h"

RLMovement::RLMovement(int y_location, int x_location, int y_safe_zone,
                       int x_safe_zone, int angle) {
  this->x_location = x_location;
  this->y_location = y_location;
  this->x_safe_zone = x_safe_zone;
  this->y_safe_zone = y_safe_zone;
  this->angle = angle;
}

void RLMovement::MoveForward() {
  x_location = x_location + cosfWrapper(angle * DEG2RAD) * 1;
  y_location = y_location + sinfWrapper(angle * DEG2RAD) * 1;

  if (pen_position == PEN_DOWN) {
    trail_points.push_back(
        {(Vector2){(float)x_location, (float)y_location}, RED});
  }
}

void RLMovement::MoveBackward() {
  x_location = x_location - cosfWrapper(angle * DEG2RAD) * 1;
  y_location = y_location - sinfWrapper(angle * DEG2RAD) * 1;

  if (pen_position == PEN_DOWN) {
    trail_points.push_back(
        {(Vector2){(float)x_location, (float)y_location}, RED});
  }
}

void RLMovement::TurnRight90() {
  angle = angle + 90;
  if (angle < 0) {
    angle = 360 - angle;
  }
}

void RLMovement::TurnLeft90() {
  angle = angle - 90;
  if (angle > 360) {
    angle = angle + 360;
  }
}