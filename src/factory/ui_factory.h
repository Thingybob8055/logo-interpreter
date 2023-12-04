#ifndef UI_FACTORY_H_
#define UI_FACTORY_H_

#include <memory>

#include "box/box.h"
#include "character_assembler/pd_character_assembler.h"
#include "movement/movement.h"
#include "renderer/renderer.h"
#include "window/window.h"
#include "recorder/recorder.h"

class UIFactory {
 public:
  virtual std::unique_ptr<Window> createWindow() = 0;
  virtual std::unique_ptr<Box> createBox(Window* window) = 0;

  virtual std::unique_ptr<Recorder> createRecorder() = 0;

  virtual std::unique_ptr<Renderer> createRenderer(Box* box,
                                                   Movement* movement, Recorder *recorder) = 0;
  virtual std::unique_ptr<CharacterAssembler> createCharacterAssembler() = 0;
  virtual std::unique_ptr<Movement> createMovement(
      float y_location, float x_location, int y_safe_zone, int x_safe_zone,
      CharacterAssembler* assembler) = 0;

  virtual ~UIFactory() = default;
};

#endif /* UI_FACTORY_H_ */
