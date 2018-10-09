#include <basic_functions.h>
#include <stdio.h>

int player_move (int m, int n, char board[][n], int *player_point, int square, char move)
{
	int row = (square-1)/n;
	int col = (square-1)%n;
	int points = 0;
	if(is_valid(m, n, board, row, col)) {
		board[row][col] = move;
		print_board(m, n, board);
		if ((points = is_point(m, n, board, row, col, move))) {
			*player_point += points;
			printf("Congradulations, you got a point! You may choose another square!\n");
			return 1;
		}
		else {
			return 0;
		}
	}
	else{
		return 1;
	}
}
