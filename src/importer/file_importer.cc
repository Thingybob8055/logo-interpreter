#include "importer/file_importer.h"

FileImporter::FileImporter(const std::string &file_name) {
  file = new std::ifstream(file_name);
  if (file->is_open()) {
    std::stringstream buffer;
    buffer << file->rdbuf();
    contents = buffer.str();
  }
}

FileImporter::~FileImporter() {
  if (file != nullptr && file->is_open()) {
    file->close();
  }
}
