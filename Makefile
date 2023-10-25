# simple malefile to compile src/main.c

bin/main: src/main.o
	gcc -o bin/main src/main.o
	make clean

main.o: main.c
	gcc -c src/main.c

clean:
	rm -f src/*o
