#####################################################################
# Makefile for compiling the project
#
# Tutorial: https://csee.essex.ac.uk/trac/ce320-06/wiki/MakefileTutorial
#####################################################################

bin/main: src/main.o
	gcc -o bin/main src/main.o
	make clean

main.o: main.c
	gcc -c src/main.c

clean:
	rm -f src/*o
