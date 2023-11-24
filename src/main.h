#include <cstdint>
#include <memory>

#include "box/box.h"
#include "character_assembler/character_assembler.h"
#include "factory/pd_factory.h"
#include "factory/ui_factory.h"
#include "importer/file_importer.h"
#include "movement/movement.h"
#include "parser/logo_parser.h"
#include "renderer/renderer.h"
#include "window/window.h"

bool ExitCommand(int command);

void RunLoop(Window *window, Renderer *graphics, Parser *parser);

bool CheckForArguments(int argc);
