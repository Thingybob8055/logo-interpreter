#include <cstdint>
#include <memory>

#include "box/pd_box.h"
#include "character_assembler/character_assembler.h"
#include "importer/file_importer.h"
#include "movement/movement.h"
#include "parser/logo_parser.h"
#include "renderer/pd_renderer.h"
#include "window/pd_window.h"

bool GetExitCommand(int command) {
  if (command == 'x') {
    return true;
  } else {
    return false;
  }
}

void RunLoop(PDWindow *window, PDRenderer *graphics, Parser *parser) {
  while (parser->HasNext()) {
    parser->Next();
    int command = parser->GetCommand();
    int magnitude = parser->GetMagnitude();
#ifdef DEBUG
    std::cout << "Command: " << command << " Magnitude: " << magnitude
              << std::endl;
#endif
    graphics->Move(command, magnitude);
    graphics->Render();
    wrefresh(window->GetWindow());
  }
  wgetch(window->GetWindow());
}

bool CheckForArguments(int argc) {
  if (argc != 2) {
    std::cout << "Usage: ./main <filename>" << std::endl;
    return false;
  }
  return true;
}

int main(int argc, char **argv) {
  if (!CheckForArguments(argc)) {
    return 1;
  }

  auto fileImporter = FileImporter(argv[1]);
  auto parser = Parser(fileImporter.GetContents());

  auto window = std::make_unique<PDWindow>(argc, argv);
  auto box = std::make_unique<PDBox>(window.get());

  uint8_t start_y_coordinate = (uint8_t)box->GetYSafeZone() / 2;
  uint8_t start_x_coordinate = (uint8_t)box->GetXSafeZone() / 2;
  auto assembler = std::make_unique<CharacterAssembler>();
  auto movement = std::make_unique<Movement>(
      start_y_coordinate, start_x_coordinate, box->GetYSafeZone(),
      box->GetXSafeZone(), assembler.get());
  auto graphics = PDRenderer(window.get(), movement.get());
  RunLoop(window.get(), &graphics, &parser);
  endwin();
  return 0;
}
