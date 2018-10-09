#include <stdio.h>

int how_many_players(void)
{
	int num_players;
	do {
		printf("How many players are there? (1/2): ");
		num_players = getchar() - '0';
	} while (num_players != 1 && num_players != 2);
	return num_players;
}

void init_board(int m, int n, char board[][n])
{
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			board[i][j] = ' ';
		}
	}
}

void human_first(char *p1, char *p2)
{
	char response;
	do {
	        
		while((response = getchar()) != '\n'); // eat anything remaining up to and including the newline
		printf("Would you like to go first? (y/n): ");
		response = getchar();
	} while (response != 'y' && response != 'n' && response != 'Y' && response != 'N');
	if (response == 'Y' || response == 'y') {
		*p2 = 'c';
	}
	else {
		*p1 = 'c';
	}
}
