compile lib:  main.o node.o library.o
	@gcc -o lib node.o main.o library.o
main.o: main.c node.h library.h
	@gcc -c main.c
node.o: node.c node.h
	@gcc -c node.c
library.o: library.c library.h
	@gcc -c library.c
run: lib
	@./lib
clean:
	rm *.o
	rm lib
