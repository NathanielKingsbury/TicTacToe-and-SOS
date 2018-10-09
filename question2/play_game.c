#include <stdio.h>
#include <basic_functions.h>
#include <comp_move.h>
#include <player_move.h>

int play_game(int m, int n, char board[][n], char p1, char p2, int *player1_point, int *player2_point)
{
	int square;
	char move;
	do {
		if(p1 == 'c') {
			if(board_full(m, n, board)) break;
			printf("Computer's turn:\n");
			comp_move(m, n, board, player1_point);
		}
		else {
			printf("Player1's turn:\n");
			do {
				if(board_full(m, n, board)) break;
                        	printf("Enter a square: ");
                        	scanf("%d", &square);
                        	do {
					while(getchar() != '\n'); // eat anything remaining up to and including the newline
                                	printf("Enter a character (S/O): ");
                                	move = getchar();
                        	} while (move != 'O' && move != 'S');
                	} while (player_move(m, n, board, player1_point, square, move));
		}
		print_points(p1, p2, player1_point, player2_point);
		if(p2 == 'c') {
			if(board_full(m, n, board)) break;
			printf("Computer's turn:\n");
                        comp_move(m, n, board, player2_point);
                }
                else {
			printf("Player2's turn:\n");
                        do {
                                if(board_full(m, n, board)) break;
				printf("Enter a square: ");
                                scanf("%d", &square);
                                do {
                                        while(getchar() != '\n'); // eat anything remaining up to and including the newline
                                	printf("Enter a character (S/O): ");
                                        move = getchar();
                                } while (move != 'O' && move != 'S');
                        } while (player_move(m, n, board, player2_point, square, move));
                }
		print_points(p1, p2, player1_point, player2_point);
	} while(!board_full(m, n, board));
	return 0;
}

				
