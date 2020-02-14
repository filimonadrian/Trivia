all : trivia

trivia : trivia.o gui.o game.o 
	gcc -Wall $^ -o trivia -lncurses
trivia.o : trivia.c 
	gcc -Wall -c -g trivia.c
gui.o : gui.c
	gcc -Wall -c -g gui.c
game.o : game.c
	gcc -Wall -c -g game.c

run : trivia
	./trivia argument1 argument2
clean : 
	rm -rf *.o trivia

