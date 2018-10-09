#include <stdio.h>
#include <stdlib.h>
#include <basic_functions.h>
#include <player_move.h>

int comp_move (int m, int n, char board[][n], int *player_point)
{
	srand(time(0));
	int max_points = 0;
	char move;
	int square = 0;
	int row, col;
	int ii = 0;
	do {
		if (board_full(m, n, board)) break;
		square = 0;
		max_points = 0;
		for(int i = 0; i < m*n; i++){ //loop through all possible squares and search for highest-valued legal move
			row = i/n;
			col = i%n;
			if(is_valid(m, n, board, row, col)){
				char move_loc = 'O';
				if (is_point(m, n, board, row, col, move_loc) > max_points){
					move = move_loc;
					square = i+1;
					max_points = is_point(m, n, board, row, col, move_loc);
				}
				move_loc = 'S';
                        	if (is_point(m, n, board, row, col, move_loc) > max_points){
                                	move = move_loc;
                                	square = i+1;
					max_points = is_point(m, n, board, row, col, move_loc);
                        	}
			}
		}
		if (!square) {
			do {
				square = rand()%(m*n) + 1;
				move = 'O' + ('S' - 'O')*(rand() % 2);
				row = square/n;
				col = square%n;
				ii++;
			} while (!is_valid(m, n, board, row, col) && ii < 200);
		}
		if (!square){
			for (int j = 0; j < m*n; j++){
				row = j/n;
				col = j%n;
				if (is_valid(m, n, board, row, col)) {
					square = row*n + col + 1;
					break;
				}
			}
		}
		if (!square){
			printf("Something is very wrong. Please stop the program.");
		}
	} while (player_move (m, n, board, player_point, square, move));
}

