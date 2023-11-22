#ifndef BOX_H_
#define BOX_H_

class Box {
 public:
  virtual int GetXSafeZone() const = 0;
  virtual int GetYSafeZone() const = 0;
  virtual ~Box() = default;
};

#endif /* BOX_H_ */