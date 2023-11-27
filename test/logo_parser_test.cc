#include "parser/logo_parser.h"

#include <curses.h>
#include <gtest/gtest.h>

#include "importer/file_importer.h"
#include "keys.h"

class LogoParserTestFixture : public ::testing::Test {
 protected:
  FileImporter *import;
  virtual void SetUp() override { import = new FileImporter(); }
  virtual void TearDown() override { delete import; }
};

TEST_F(LogoParserTestFixture,
       Next_when_magnitude_read_command_with_magnitude_from_string) {
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
       Next_when_no_magnitude_read_command_without_magnitude_from_string) {
  import->SetContents("pu");
  Parser parser = Parser(import->GetContents());
  parser.Next();
  ASSERT_EQ(parser.GetCommand(), KEY_SPACE);
  ASSERT_EQ(parser.GetMagnitude(), 0);
}

TEST_F(LogoParserTestFixture, HasNext_when_no_more_commands_then_false) {
  import->SetContents("pu");
  Parser parser = Parser(import->GetContents());
  parser.Next();
  ASSERT_FALSE(parser.HasNext());
}

TEST_F(LogoParserTestFixture, HasNext_when_more_commands_then_true) {
  import->SetContents("pu\nfd 100");
  Parser parser = Parser(import->GetContents());
  parser.Next();
  ASSERT_TRUE(parser.HasNext());
}
