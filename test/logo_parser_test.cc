#include "parser/logo_parser.h"

#include <gtest/gtest.h>

#include "importer/file_importer.h"

class LogoParserTestFixture : public ::testing::Test {
 protected:
  FileImporter *import;
  virtual void SetUp() override { import = new FileImporter(); }
  virtual void TearDown() override { delete import; }
};

TEST_F(LogoParserTestFixture, correctly_read_commands_from_lgo_file) {
  import->SetContents("fd 100\nrt 90");
  Parser parser = Parser(import->GetContents());
  parser.Next();
  ASSERT_EQ(parser.GetCommand(), KEY_UP);
  ASSERT_EQ(parser.GetMagnitude(), 100);
  parser.Next();
  ASSERT_EQ(parser.GetCommand(), KEY_RIGHT);
  ASSERT_EQ(parser.GetMagnitude(), 90);
}

TEST_F(LogoParserTestFixture,
       correctly_read_command_without_magnitude_from_lgo_file) {
  import->SetContents("pu");
  Parser parser = Parser(import->GetContents());
  parser.Next();
  ASSERT_EQ(parser.GetCommand(), KEY_SPACE);
  ASSERT_EQ(parser.GetMagnitude(), 0);
}
