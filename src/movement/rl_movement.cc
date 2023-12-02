#include "rl_movement.h"

RLMovement::RLMovement(int y_location, int x_location, int y_safe_zone,
                       int x_safe_zone, RLCharacterAssembler *assembler) {
  this->x_location = x_location;
  this->y_location = y_location;
  this->x_safe_zone = x_safe_zone;
  this->y_safe_zone = y_safe_zone;
  this->assembler = assembler;
}

void RLMovement::MoveForward() {
  x_location = x_location +
               cosfWrapper((int)assembler->GetCurrentHeading() * DEG2RAD) * 1;
  y_location = y_location +
               sinfWrapper((int)assembler->GetCurrentHeading() * DEG2RAD) * 1;

  if (pen_position == PEN_DOWN) {
    trail_points.push_back(
        {(Vector2){(float)x_location, (float)y_location}, RED});
  }
}

void RLMovement::MoveBackward() {
  x_location = x_location -
               cosfWrapper((int)assembler->GetCurrentHeading() * DEG2RAD) * 1;
  y_location = y_location -
               sinfWrapper((int)assembler->GetCurrentHeading() * DEG2RAD) * 1;

  if (pen_position == PEN_DOWN) {
    trail_points.push_back(
        {(Vector2){(float)x_location, (float)y_location}, RED});
  }
}

void RLMovement::TurnRight90() {
  auto angle = (int)assembler->GetCurrentHeading();
  angle = angle + 90;
  if (angle < 0) {
    angle = 360 - angle;
  }
  assembler->SetCurrentHeading((Heading)angle);
}

void RLMovement::TurnLeft90() {
  auto angle = (int)assembler->GetCurrentHeading();
  angle = angle - 90;
  if (angle > 360) {
    angle = angle + 360;
  }
  assembler->SetCurrentHeading((Heading)angle);
}