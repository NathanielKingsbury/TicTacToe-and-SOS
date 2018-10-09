# this will create your final output using the .o compiled files
make: tictactoe.o computer_moves.o basic_functions.o player_moves.o
	gcc -o TicTacToe tictactoe.o computer_moves.o basic_functions.o player_moves.o -I.

# this will compile basic_functions.c
basic_functions.o: basic_functions.c basic_functions.h
	gcc -c basic_functions.c -I.

# this will compile computer_moves.c with its dependancies
computer_moves.o: computer_moves.c computer_moves.h basic_functions.h
	gcc -c computer_moves.c -I.

#this will compile player_moves.c
player_moves.o: player_moves.c player_moves.h
	gcc -c player_moves.c -I.

# this will compile tictactoe.c with its dependancies
tictactoe.o: tictactoe.c basic_functions.h computer_moves.h player_moves.h
	gcc -c tictactoe.c -I.

# this will clean or remove compiled files so you can start from fresh
clean:
	rm -f *.o *.exe
