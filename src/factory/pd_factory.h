#ifndef PD_FACTORY_H_
#define PD_FACTORY_H_

#include <memory>

#include "box/box.h"
#include "box/pd_box.h"
#include "character_assembler/character_assembler.h"
#include "character_assembler/pd_character_assembler.h"
#include "factory/ui_factory.h"
#include "movement/movement.h"
#include "movement/pd_movement.h"
#include "recorder/noop_recorder.h"
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

  std::unique_ptr<Recorder> createRecorder(Window* window) override {
    return std::make_unique<NoopRecorder>();
  }

  std::unique_ptr<Renderer> createRenderer(
      Box* box, Movement* movement, Recorder* recorder = nullptr) override {
    return std::make_unique<PDRenderer>(static_cast<PDBox*>(box),
                                        static_cast<PDMovement*>(movement));
  }

  std::unique_ptr<CharacterAssembler> createCharacterAssembler() override {
    return std::make_unique<PDCharacterAssembler>();
  }

  std::unique_ptr<Movement> createMovement(
      float y_location, float x_location, int y_safe_zone, int x_safe_zone,
      CharacterAssembler* assembler) override {
    return std::make_unique<PDMovement>(
        (int)y_location, (int)x_location, y_safe_zone, x_safe_zone,
        static_cast<PDCharacterAssembler*>(assembler));
  }
};

#endif /* PD_FACTORY_H_ */
