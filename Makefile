#####################################################################
# Makefile for compiling the project
#
# Tutorial: https://csee.essex.ac.uk/trac/ce320-06/wiki/MakefileTutorial
#####################################################################

.PHONY: test format clean coverage_clean rm run run_test gen_report

CXX = g++
CXXFLAGS = -std=c++17 -DHAVE_CONFIG_H -DXCURSES  -DPDC_WIDE -DPDC_FORCE_UTF8
INCLUDE = -I./src -I/usr/local/include/xcurses -I/usr/include/X11 -I/usr/include
LIBS = /usr/local/lib/libXCurses.a -lXaw -lXmu -lXt -lX11 -lXpm -lSM -lICE -lXext
OBJS = main.o pd_renderer.o pd_window.o
EXEC = bin/main
TEST_EXEC = bin/test_main
SRCS_MAIN = src/main.cc $(SRCS)
SRCS = src/renderer/pd_renderer.cc src/window/pd_window.cc
TEST_SRCS = test/pd_renderer_test.cc test/test_all.cc $(SRCS)
TEST_CXXFLAGS = -fprofile-arcs -ftest-coverage $(CXXFLAGS)
TEST_LIBS = -lgtest -lgtest_main -lpthread -fprofile-arcs -ftest-coverage
TEST_INCLUDE = -I./src
REPORTS_DIR = reports

ifeq ($(OS),Windows_NT)
    $(error Windows is not supported)
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        LIBS += -L/usr/X11/lib -L/opt/homebrew/lib
        INCLUDE += -I/opt/homebrew/include
    endif
endif

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS)
	make clean

$(OBJS): $(SRCS_MAIN)
	$(CXX) -c $(CXXFLAGS) $(INCLUDE) $(SRCS_MAIN)

test: $(TEST_SRCS)
	$(CXX) $(TEST_CXXFLAGS) $(INCLUDE) $(TEST_INCLUDE) $(TEST_SRCS) -o $(TEST_EXEC) $(LIBS) $(TEST_LIBS)
	make clean

format:
	find . -type f \( -name "*.h" -o -name "*.cc" -o -name "*.c" \) | xargs clang-format -i

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
	rm -rf *.gcda; rm -rf *.gcno; rm -rf *.gcov

gen_report: coverage_clean test
	./$(TEST_EXEC) --gtest_output="xml:$(REPORTS_DIR)/gtest-report.xml"
	gcovr --filter src/ --html-details $(REPORTS_DIR)/coverage.html
	make coverage_clean
