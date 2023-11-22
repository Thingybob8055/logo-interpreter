#ifndef RENDERER_H_
#define RENDERER_H_

class Renderer {
 public:
  virtual void Move(int command, int magnitude) = 0;
  virtual int Render() = 0;
  virtual ~Renderer() = default;
};

#endif /* RENDERER_H_ */