#ifndef MAIN_H
#define MAIN_H

#include <cstdint>
#include <memory>
#include <sstream>

#include "box/box.h"
#include "character_assembler/pd_character_assembler.h"
#include "factory/pd_factory.h"
#include "factory/rl_factory.h"
#include "factory/ui_factory.h"
#include "importer/file_importer.h"
#include "movement/movement.h"
#include "parser/logo_line_break_handler.h"
#include "parser/logo_parser.h"
#include "parser/logo_repeat_handler.h"
#include "renderer/renderer.h"
#include "window/window.h"

bool GetExitCommand(int command);

void RunLoop(Window *window, Renderer *graphics, Parser *parser);

bool CheckForArguments(int argc);

#endif /* MAIN_H_ */