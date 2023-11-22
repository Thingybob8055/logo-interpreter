#ifndef PD_FACTORY_H_
#define PD_FACTORY_H_

#include <memory>

#include "box/box.h"
#include "box/pd_box.h"
#include "factory/ui_factory.h"
#include "movement/movement.h"
#include "renderer/pd_renderer.h"
#include "renderer/renderer.h"
#include "window/pd_window.h"
#include "window/window.h"

class PDFactory : public UIFactory {
 public:
  std::unique_ptr<Window> createWindow() override {
    return std::make_unique<PDWindow>();
  }
  std::unique_ptr<Box> createBox(Window* window) override {
    return std::make_unique<PDBox>(static_cast<PDWindow*>(window));
  }
  std::unique_ptr<Renderer> createRenderer(Window* window,
                                           Movement* movement) override {
    return std::make_unique<PDRenderer>(static_cast<PDWindow*>(window),
                                        movement);
  }
};

#endif /* PD_FACTORY_H_ */
