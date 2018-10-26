build: task1.o pacman.o execute
	gcc -Wall task1.o -o task1
	gcc -Wall pacman.o -o pacman

execute: task1.c pacman.c
	gcc -c -Wall task1.c -o task1.o
	gcc -c -Wall pacman.c -o pacman.o

clean:
	rm -f *.o pacman task1

