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
  FileImporter(std::string fileName);
  ~FileImporter();

  std::string GetContents() { return contents; }

  void SetContents(std::string contents) { this->contents = contents; }
};

#endif /* FILE_IMPORTER_H_ */
