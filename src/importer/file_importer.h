#ifndef FILE_IMPORTER_H_
#define FILE_IMPORTER_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>

class FileImporter {
 private:
  std::unique_ptr<std::ifstream> file = nullptr;
  std::string contents;

 public:
  FileImporter() = default;
  explicit FileImporter(const std::string &file_name);
  ~FileImporter();

  std::string GetContents() const { return contents; }

  void SetContents(std::string_view contents) { this->contents = contents; }
};

#endif /* FILE_IMPORTER_H_ */
