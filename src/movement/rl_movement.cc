#include "rl_movement.h"

RLMovement::RLMovement(float y_location, float x_location, int y_safe_zone,
                       int x_safe_zone, RLCharacterAssembler *assembler)
    : x_location(x_location),
      y_location(y_location),
      x_safe_zone(x_safe_zone),
      y_safe_zone(y_safe_zone),
      assembler(assembler) {}

void RLMovement::MoveForward() {
  x_location = (x_location +
                cosfWrapper((int)assembler->GetCurrentHeading() * DEG2RAD) * 1);
  y_location = (y_location +
                sinfWrapper((int)assembler->GetCurrentHeading() * DEG2RAD) * 1);

  WrapLocation();

  if (pen_position == PEN_DOWN) {
    trail_points.push_back({(Vector2){x_location, y_location}, RED});
  }
}

void RLMovement::MoveBackward() {
  x_location = (x_location -
                cosfWrapper((int)assembler->GetCurrentHeading() * DEG2RAD) * 1);
  y_location = (y_location -
                sinfWrapper((int)assembler->GetCurrentHeading() * DEG2RAD) * 1);

  WrapLocation();

  if (pen_position == PEN_DOWN) {
    trail_points.push_back({(Vector2){x_location, y_location}, RED});
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

void RLMovement::TurnRight(int angle) {
  auto current_angle = (int)assembler->GetCurrentHeading();
  current_angle = current_angle + angle;
  if (current_angle < 0) {
    current_angle = 360 - current_angle;
  }
  assembler->SetCurrentHeading((Heading)current_angle);
}

void RLMovement::TurnLeft(int angle) {
  auto current_angle = (int)assembler->GetCurrentHeading();
  current_angle = current_angle - angle;
  if (current_angle > 360) {
    current_angle = current_angle + 360;
  }
  assembler->SetCurrentHeading((Heading)current_angle);
}

void RLMovement::WrapLocation() {
  static int ceiling_cap = 0;
  if (x_location > (float)x_safe_zone) {
    x_location = (float)ceiling_cap;
  } else if (x_location < (float)ceiling_cap) {
    x_location = (float)x_safe_zone;
  }

  if (y_location > (float)y_safe_zone) {
    y_location = (float)ceiling_cap;
  } else if (y_location < (float)ceiling_cap) {
    y_location = (float)y_safe_zone;
  }
}