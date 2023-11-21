#ifndef FILE_IMPORTER_H_
#define FILE_IMPORTER_H_

#include <fstream>
#include <iostream>
#include <sstream>

class FileImporter {
 private:
  std::ifstream *file;
  std::string contents;

 public:
  FileImporter();
  explicit FileImporter(std::string file_name);
  ~FileImporter();

  std::string GetContents() const { return contents; }

  void SetContents(std::string contents) { this->contents = contents; }
};

#endif /* FILE_IMPORTER_H_ */
