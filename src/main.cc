#include <cstdint>

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

void FreeMemory(PDWindow *window, PDBox *box, CharacterAssembler *assembler,
                Movement *movement) {
  endwin();
  delete window;
  delete box;
  delete assembler;
  delete movement;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./logo <filename>" << std::endl;
    return 1;
  }

  auto fileImporter = FileImporter(argv[1]);
  auto parser = Parser(fileImporter.GetContents());

  auto *window = new PDWindow(argc, argv);
  auto *box = new PDBox(window);
  box->CreateBox();

  uint8_t start_y_coordinate = box->GetYSafeZone() / 2;
  uint8_t start_x_coordinate = box->GetXSafeZone() / 2;
  CharacterAssembler *assembler = new CharacterAssembler();
  Movement *movement =
      new Movement(start_y_coordinate, start_x_coordinate, box->GetYSafeZone(),
                   box->GetXSafeZone(), assembler);
  auto graphics = PDRenderer(window, movement);
  RunLoop(window, &graphics, &parser);

  FreeMemory(window, box, assembler, movement);
  return 0;
}
