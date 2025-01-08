compile lib:  main.o node.o library.o playlist.o
	@gcc -o lib node.o main.o library.o playlist.o
main.o: main.c node.h library.h playlist.h
	@gcc -c main.c
node.o: node.c node.h
	@gcc -c node.c
playlist.o: playlist.c playlist.h
	@gcc -c playlist.c
library.o: library.c library.h
	@gcc -c library.c
run: lib
	@./lib
clean:
	rm *.o
	rm lib
