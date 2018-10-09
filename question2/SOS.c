#include <stdio.h>
#include <init_functions.h>
#include <basic_functions.h>
#include <player_move.h>
#include <play_game.h>

int main()
{
	int rows, cols, square;
	char move;
	int p1_points = 0;
	int p2_points = 0;
	char p1 = 'h';
	char p2 = 'h';
	int players = how_many_players();
	if (!(players-1)) {
		human_first(&p1, &p2);
	}
	printf("How many rows would you like? Please enter a natural number: ");
	scanf("%d", &rows);
	printf("How many columns would you like? Please enter a natural number: ");
	scanf("%d", &cols);
	char board[rows][cols];
	do {
		p1_points = 0;
		p2_points = 0;
		init_board(rows, cols, board);
	        print_board(rows, cols, board);
		play_game(rows, cols, board, p1, p2, &p1_points, &p2_points);
		if (p1_points > p2_points){
			if (p1 == 'c'){
				printf("I win, you petty human!!!\n");
			}
			else {
				printf("Player1 wins!!!\n");
			}
		}
		else if (p2_points > p1_points) {
			if (p2 == 'c'){
		        	printf("I win, you petty human!!!\n");
                	}
                	else {
                        	printf("Player2 wins!!!\n");
                	}
		}
		else{
			printf("The game is a draw.\n");
		}
	} while(play_again());
	return 0;
}
