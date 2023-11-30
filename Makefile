#####################################################################
# Makefile for compiling the project
#
# Tutorial: https://csee.essex.ac.uk/trac/ce320-06/wiki/MakefileTutorial
#####################################################################

.PHONY: test format clean coverage_clean rm run run_test gen_report

CXX = g++
CXXFLAGS = -std=c++20 -DHAVE_CONFIG_H -DXCURSES  -DPDC_WIDE -DPDC_FORCE_UTF8 -DPLATFORM_DESKTOP
INCLUDE = -I./src -I/usr/local/include/xcurses -I/usr/include/X11 -I/usr/include
PD_LIBS = /usr/local/lib/libXCurses.a -lXaw -lXmu -lXt -lX11 -lXpm -lSM -lICE -lXext
RL_LIBS = -lraylib -lGL -lm -lpthread -ldl
LIBS =  $(PD_LIBS) $(RL_LIBS)
OBJS = main.o file_importer.o pd_renderer.o pd_window.o pd_movement.o logo_parser.o character_assembler.o pd_box.o rl_box.o rl_window.o raylib_wrapper.o rl_renderer.o logo_repeat_handler.o logo_line_break_handler.o
EXEC = bin/main
TEST_EXEC = bin/test_main
SRCS_MAIN = src/main.cc src/raylib_wrapper/raylib_wrapper.cc $(SRCS)
SRCS = src/importer/file_importer.cc src/renderer/pd_renderer.cc src/window/pd_window.cc src/movement/pd_movement.cc src/parser/logo_parser.cc src/character_assembler/character_assembler.cc src/box/pd_box.cc src/box/rl_box.cc src/window/rl_window.cc src/renderer/rl_renderer.cc src/parser/logo_repeat_handler.cc src/parser/logo_line_break_handler.cc
TEST_SRCS = test/file_importer_test.cc test/pd_renderer_test.cc test/movement_test.cc test/logo_parser_test.cc test/test_all.cc test/character_assembler_test.cc test/pd_window_test.cc test/main_test.cc test/rl_window_test.cc test/rl_box_test.cc test/rl_renderer_test.cc test/logo_repeat_handler_test.cc test/logo_line_break_handler_test.cc test/fff_common.cc $(SRCS)
TEST_CXXFLAGS = -fprofile-arcs -ftest-coverage $(CXXFLAGS) -DTEST
TEST_LIBS = -lgtest -lgtest_main -lpthread -fprofile-arcs -ftest-coverage
TEST_INCLUDE = -I./src
REPORTS_DIR = reports

ifeq ($(OS),Windows_NT)
    $(error Windows is not supported)
else ifeq ($(shell uname -s),Linux)
	COVERAGE_DIR = bin
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        PD_LIBS += -L/usr/X11/lib -L/opt/homebrew/lib
        RL_LIBS += -L/usr/X11/lib -L/opt/homebrew/lib
        INCLUDE += -I/opt/homebrew/include
		COVERAGE_DIR = .
    endif
endif

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS)
	make clean

$(OBJS): $(SRCS_MAIN)
	$(CXX) -c $(CXXFLAGS) $(INCLUDE) $(SRCS_MAIN)

test: $(TEST_SRCS)
	$(CXX) $(TEST_CXXFLAGS) $(INCLUDE) $(TEST_INCLUDE) $(TEST_SRCS) -o $(TEST_EXEC) $(PD_LIBS) $(TEST_LIBS)
	make clean

format:
	find . -type f \( -name "*.h" -o -name "*.cc" -o -name "*.c" \) | xargs clang-format -style=Google -i

clean:
	rm -f *.o

rm:
	rm -f $(EXEC)
	rm -f $(TEST_EXEC)
	rm -rf $(REPORTS_DIR)
	make coverage_clean

run:
	xrdb -merge src/xresource && ./$(EXEC)

run_test:
	xrdb -merge src/xresource && ./$(TEST_EXEC)

coverage_clean:
	rm -rf $(COVERAGE_DIR)/*.gcda; rm -rf $(COVERAGE_DIR)/*.gcno; rm -rf $(COVERAGE_DIR)/*.gcov

gen_report: coverage_clean test
	./$(TEST_EXEC) --gtest_output="xml:$(REPORTS_DIR)/gtest-report.xml"
	gcovr --filter src/ --html-details $(REPORTS_DIR)/coverage.html
	make coverage_clean
