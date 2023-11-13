#####################################################################
# Makefile for compiling the project
#
# Tutorial: https://csee.essex.ac.uk/trac/ce320-06/wiki/MakefileTutorial
#####################################################################

CXX = g++
CXXFLAGS = -std=c++17 -O2 -DHAVE_CONFIG_H -DXCURSES  -DPDC_WIDE -DPDC_FORCE_UTF8
INCLUDE = -I/usr/local/include/xcurses  -I/usr/include/X11 -I/usr/include
LIBS = -lXCurses -lXaw -lXmu -lXt -lX11 -lXpm -lSM -lICE -lXext
OBJS = main.o pd_renderer.o
EXEC = bin/main
TEST_EXEC = bin/test_main
SRCS_MAIN = src/main.c $(SRCS)
SRCS = src/pd_renderer.c
TEST_SRCS = test/pd_renderer.cc test/test_all.cc $(SRCS)
TEST_LIBS = -lgtest -lgtest_main -lpthread
TEST_INCLUDE = -I./src
REPORTS_DIR = reports

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS)
	make clean

test: $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(TEST_INCLUDE) $(TEST_SRCS) -o $(TEST_EXEC) $(LIBS) $(TEST_LIBS)
	make clean

$(OBJS): $(SRCS_MAIN)
	$(CXX) -c $(CXXFLAGS) $(INCLUDE) $(SRCS_MAIN)

clean:
	rm -f *.o

make rm:
	rm -f $(EXEC)
	rm -f $(TEST_EXEC)
	rm -rf $(REPORTS_DIR)

run:
	xrdb -merge src/xresource && ./$(EXEC)

run_test:
	xrdb -merge src/xresource && ./$(TEST_EXEC)

gen_report: test
	./$(TEST_EXEC) --gtest_output="xml:$(REPORTS_DIR)/gtest-report.xml"
