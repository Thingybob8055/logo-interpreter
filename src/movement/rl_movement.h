#ifndef RL_MOVEMENT_H_
#define RL_MOVEMENT_H_

#include "heading.h"
#include "movement.h"
#include "pen_position.h"
#include "raylib_wrapper/raylib_wrapper.h"
#include <vector>

struct TrailPoint {
  Vector2 position;
  Color color;
};

class RLMovement : public Movement {
 private:
  int x_location;
  int y_location;
  int x_safe_zone;
  int y_safe_zone;
  int angle;

  // TODO:  make a boundry check function
  PenPosition pen_position = PEN_DOWN;
  std::vector<TrailPoint> trail_points;

 public:
  RLMovement(int y_location, int x_location, int y_safe_zone, int x_safe_zone, int angle);

  void MoveForward() override;
  void MoveBackward() override;
  void TurnRight90() override;
  void TurnLeft90() override;

  int GetXLocation() const override { return x_location; }
  int GetYLocation() const override { return y_location; }
  int GetAngle() const { return angle; }
  PenPosition GetPenPosition() const override { return pen_position; }
  int GetXSafeZone() const { return x_safe_zone; }
  int GetYSafeZone() const { return y_safe_zone; }
  void SetPenPosition(PenPosition pen_position) override {
    this->pen_position = pen_position;
  }

  std::vector<TrailPoint> GetTrailPoints() const { return trail_points; }

};

#endif /* RL_MOVEMENT_H_ */