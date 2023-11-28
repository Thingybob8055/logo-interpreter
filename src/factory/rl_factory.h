#ifndef RL_FACTORY_H_
#define RL_FACTORY_H_

#include <memory>

#include "box/box.h"
#include "box/rl_box.h"
#include "factory/ui_factory.h"
#include "movement/movement.h"
#include "renderer/renderer.h"
#include "renderer/rl_renderer.h"
#include "window/rl_window.h"
#include "window/window.h"

class RLFactory : public UIFactory {
 public:
  std::unique_ptr<Window> createWindow() override {
    return std::make_unique<RLWindow>();
  }
  std::unique_ptr<Box> createBox(Window* window) override {
    return std::make_unique<RLBox>();
  }
  std::unique_ptr<Renderer> createRenderer(Window* window,
                                           Movement* movement) override {
    return std::make_unique<RLRenderer>(movement);
  }
};

#endif /* RL_FACTORY_H_ */