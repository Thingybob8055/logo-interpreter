#ifndef UI_FACTORY_H_
#define UI_FACTORY_H_

#include <memory>

#include "box/box.h"
#include "character_assembler/character_assembler.h"
#include "movement/movement.h"
#include "renderer/renderer.h"
#include "window/window.h"

class UIFactory {
 public:
  virtual std::unique_ptr<Window> createWindow() = 0;
  virtual std::unique_ptr<Box> createBox(Window* window) = 0;
  virtual std::unique_ptr<Renderer> createRenderer(Box* box,
                                                   Movement* movement) = 0;
  virtual std::unique_ptr<Movement> createMovement(
      int y_location, int x_location, int y_safe_zone, int x_safe_zone,
      int angle, CharacterAssembler* assembler) = 0;

  virtual ~UIFactory() = default;
};

#endif /* UI_FACTORY_H_ */
