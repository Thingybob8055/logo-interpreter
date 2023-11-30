#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include "pen_position.h"

class Movement {
 public:
  virtual void MoveForward() = 0;
  virtual void MoveBackward() = 0;
  virtual void TurnRight90() = 0;
  virtual void TurnLeft90() = 0;

  virtual int GetXLocation() const = 0;
  virtual int GetYLocation() const = 0;

  virtual void SetPenPosition(PenPosition pen_position) = 0;
  virtual PenPosition GetPenPosition() const = 0;

  virtual ~Movement() = default;
};

#endif /* MOVEMENT_H_ */