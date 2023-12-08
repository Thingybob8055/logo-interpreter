#include "main.h"

bool GetExitCommand(int command) {
  if (command == 'x') {
    return true;
  } else {
    return false;
  }
}

void ParseLoop(std::stringstream &ss) {
  auto repeatHandler = LogoRepeatHandler();
  auto lbHandler = LogoLineBreakHandler();
  int max_repeat = 10;
  for (size_t i = 0; i < max_repeat; i++) {
    auto out = repeatHandler.Handle(ss);
    if (out.str().compare(ss.str()) == 0) {
      std::cout << "No more repeats" << std::endl;
      break;
    }
    ss = lbHandler.Handle(out);
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

  while (!window->ShouldExit()) {
    graphics->Render();
  }
}

bool CheckForArguments(int argc) {
  if (argc != 3) {
    std::cout << "Usage: ./main <filename> <pd/rl>" << std::endl;
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
  std::stringstream ss;
  ss << fileImporter.GetContents();
  ParseLoop(ss);
  auto parser = Parser(ss.str());

  std::unique_ptr<UIFactory> ui_factory;
  if (strcmp(argv[2], "pd") == 0) {
    ui_factory = std::make_unique<PDFactory>();
  } else if (strcmp(argv[2], "rl") == 0) {
    ui_factory = std::make_unique<RLFactory>();
  } else {
    std::cout << "Usage: ./main <filename> <pd/rl>" << std::endl;
    return 1;
  }
  auto window = ui_factory->createWindow();
  auto box = ui_factory->createBox(window.get());

  int start_y_coordinate = box->GetYSafeZone() / 2;
  int start_x_coordinate = box->GetXSafeZone() / 2;

  auto assembler = ui_factory->createCharacterAssembler();
  auto recorder = ui_factory->createRecorder(window.get());

  auto movement = ui_factory->createMovement(
      start_y_coordinate, start_x_coordinate, box->GetYSafeZone(),
      box->GetXSafeZone(), assembler.get());
  auto graphics =
      ui_factory->createRenderer(box.get(), movement.get(), recorder.get());
  RunLoop(window.get(), graphics.get(), &parser);

  return 0;
}
#endif
