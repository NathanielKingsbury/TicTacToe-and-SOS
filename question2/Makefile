#this will create the final output using the .o compiled files
make: SOS.o init_functions.o basic_functions.o player_move.o play_game.o comp_move.o
	gcc -o SOS SOS.o init_functions.o basic_functions.o player_move.o play_game.o comp_move.o -I.

#this will compile init_functions.c
init_functions.o: init_functions.c init_functions.h
	gcc -c init_functions.c -I.

#this will compile basic_functions.c
basic_functions.o: basic_functions.c basic_functions.h
	gcc -c basic_functions.c -I.

#this will compile player_move.c with its dependencies
player_move.o: player_move.c player_move.h basic_functions.h
	gcc -c player_move.c -I.

#this will compile comp_move.c with its dependencies
comp_move.o: comp_move.c basic_functions.h player_move.h
	gcc -c comp_move.c -I.

#this will compile play_game.c with its dependencies
play_game.o: play_game.c comp_move.h basic_functions.h player_move.h
	gcc -c play_game.c -I.

#this will compile SOS.c with its dependencies
SOS.o: SOS.c basic_functions.h init_functions.h player_move.h play_game.h
	gcc -c SOS.c -I.

#this will clear all .exe and .o files so you can start from scratch
clean:
	rm -f *.exe *.o
