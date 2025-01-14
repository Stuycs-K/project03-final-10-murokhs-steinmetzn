compile lib:  main.o node.o library.o playlist.o mp3.o
	@gcc -o lib node.o main.o library.o playlist.o mp3.o
main.o: main.c node.h library.h playlist.h mp3.h
	@gcc -c main.c
node.o: node.c node.h
	@gcc -c node.c
playlist.o: playlist.c playlist.h
	@gcc -c playlist.c
library.o: library.c library.h
	@gcc -c library.c
mp3.c: mp3.c mp3.h
	@gcc -c mp3.c
run: lib
	@./lib
clean:
	rm *.o
	rm lib
