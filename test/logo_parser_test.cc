#include "parser/logo_parser.h"
#include "importer/file_importer.h"

#include <gtest/gtest.h>

TEST(ParserTest, correctly_read_commands_from_lgo_file) {
    FileImporter import = FileImporter("assets/square.lgo");
    Parser parser = Parser(import.GetContents());
    parser.Next();
    ASSERT_EQ(parser.GetCommand(), KEY_UP);
    ASSERT_EQ(parser.GetMagnitude(), 100);
    parser.Next();
    ASSERT_EQ(parser.GetCommand(), KEY_RIGHT);
    ASSERT_EQ(parser.GetMagnitude(), 90);
}