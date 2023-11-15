#include "importer/file_importer.h"

#include <gtest/gtest.h>

class FileImporterTestFixture : public ::testing::Test {
protected:
  std::string fileName;
  std::ofstream fp;

  virtual void SetUp() override {
    fileName = std::tmpnam(nullptr);
    std::cout << "temporary file name: " << fileName << '\n';

    fp = std::ofstream(fileName);
  }
  virtual void TearDown() override { 
    std::remove(fileName.c_str());
    fp.close();
    }
};

TEST_F(FileImporterTestFixture,
       when_constructed_expect_specified_file_to_be_read) {
  fp << "Hello World!" << std::endl;
  FileImporter fileImporter = FileImporter(this->fileName);
  EXPECT_EQ("Hello World!\n", fileImporter.GetContents());
}
