#include "importer/file_importer.h"

#include <gtest/gtest.h>

class FileImporterTestFixture : public ::testing::Test {
 protected:
  std::string file_name;
  std::ofstream fp;

  virtual void SetUp() override {
    file_name = std::tmpnam(nullptr);
    std::cout << "temporary file name: " << file_name << '\n';

    fp = std::ofstream(file_name);
  }
  virtual void TearDown() override {
    std::remove(file_name.c_str());
    fp.close();
  }
};

TEST_F(FileImporterTestFixture,
       when_constructed_expect_specified_file_to_be_read) {
  fp << "Hello World!" << std::endl;
  FileImporter fileImporter = FileImporter(this->file_name);
  EXPECT_EQ("Hello World!\n", fileImporter.GetContents());
}
