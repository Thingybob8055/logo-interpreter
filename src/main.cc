#include "main.h"

bool GetExitCommand(int command) {
  if (command == 'x') {
    return true;
  } else {
    return false;
  }
}

void RunLoop(Window *window, Renderer *graphics, Parser *parser) {
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
  }
  window->GetInput();
}

bool CheckForArguments(int argc) {
  if (argc != 2) {
    std::cout << "Usage: ./main <filename>" << std::endl;
    return false;
  }
  return true;
}

#ifndef TEST
int main(int argc, char **argv) {
  if (!CheckForArguments(argc)) {
    return 1;
  }

  auto fileImporter = FileImporter(argv[1]);
  auto parser = Parser(fileImporter.GetContents());

  std::unique_ptr<UIFactory> ui_factory = std::make_unique<PDFactory>();
  auto window = ui_factory->createWindow();
  auto box = ui_factory->createBox(window.get());

  uint8_t start_y_coordinate = (uint8_t)box->GetYSafeZone() / 2;
  uint8_t start_x_coordinate = (uint8_t)box->GetXSafeZone() / 2;
  auto assembler = std::make_unique<CharacterAssembler>();
  auto movement = std::make_unique<Movement>(
      start_y_coordinate, start_x_coordinate, box->GetYSafeZone(),
      box->GetXSafeZone(), assembler.get());
  auto graphics = ui_factory->createRenderer(window.get(), movement.get());
  RunLoop(window.get(), graphics.get(), &parser);
  return 0;
}
#endif
