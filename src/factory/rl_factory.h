#ifndef RL_FACTORY_H_
#define RL_FACTORY_H_

#include <memory>

#include "box/box.h"
#include "box/rl_box.h"
#include "character_assembler/character_assembler.h"
#include "character_assembler/rl_character_assembler.h"
#include "factory/ui_factory.h"
#include "movement/movement.h"
#include "movement/rl_movement.h"
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
  std::unique_ptr<Renderer> createRenderer(Box* box,
                                           Movement* movement) override {
    return std::make_unique<RLRenderer>(static_cast<RLBox*>(box),
                                        static_cast<RLMovement*>(movement));
  }

  std::unique_ptr<CharacterAssembler> createCharacterAssembler() override {
    return std::make_unique<RLCharacterAssembler>();
  }

  std::unique_ptr<Movement> createMovement(
      float y_location, float x_location, int y_safe_zone, int x_safe_zone,
      CharacterAssembler* assembler = nullptr) override {
    return std::make_unique<RLMovement>(
        y_location, x_location, y_safe_zone, x_safe_zone,
        static_cast<RLCharacterAssembler*>(assembler));
  }
};

#endif /* RL_FACTORY_H_ */