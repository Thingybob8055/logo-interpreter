#ifndef UI_FACTORY_H_
#define UI_FACTORY_H_

#include <memory>

#include "box/box.h"
#include "movement/movement.h"
#include "renderer/renderer.h"
#include "window/window.h"

class UIFactory {
 public:
  virtual std::unique_ptr<Window> createWindow() = 0;
  virtual std::unique_ptr<Box> createBox(Window* window = nullptr) = 0;
  virtual std::unique_ptr<Renderer> createRenderer(Window* window,
                                                   Movement* movement) = 0;

  virtual ~UIFactory() = default;
};

#endif /* UI_FACTORY_H_ */
