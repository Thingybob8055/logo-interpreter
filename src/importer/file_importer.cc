#include "importer/file_importer.h"

FileImporter::FileImporter(std::string fileName) {
  // TODO: Tokenizer: lex & yacc (External libs we are allowed to use)
  file = new std::ifstream(fileName);
  if (file->is_open()) {
    std::stringstream buffer;
    buffer << file->rdbuf();
    contents = buffer.str();
  }
}

FileImporter::~FileImporter() { file->close(); }
