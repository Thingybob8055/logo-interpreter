#ifndef MAIN_H
#define MAIN_H

#include <cstdint>
#include <memory>

#include "box/box.h"
#include "character_assembler/character_assembler.h"
#include "factory/pd_factory.h"
#undef KEY_ENTER
#undef KEY_BACKSPACE
#undef KEY_UP
#undef KEY_DOWN
#undef KEY_LEFT
#undef KEY_RIGHT
#undef KEY_HOME
#undef KEY_END
#include "factory/rl_factory.h"
#include "factory/ui_factory.h"
#include "importer/file_importer.h"
#include "movement/movement.h"
#include "parser/logo_parser.h"
#include "renderer/renderer.h"
#include "window/window.h"

bool GetExitCommand(int command);

void RunLoop(Window *window, Renderer *graphics, Parser *parser);

bool CheckForArguments(int argc);

#endif /* MAIN_H_ */