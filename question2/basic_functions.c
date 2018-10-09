#include <stdio.h>

void print_board(int m, int n, char board[][n])
{
  int row, col;

  printf("\n");
  for (row = 0; row < m; row++)
  {
          for (col = 0; col < n-1; col++)
          {
                  printf("   *");
          }
          printf ("   \n");
          for (col = 0; col < n-1; col++)
          {
                  printf(" %c *", board[row][col]);
          }
          printf (" %c \n", board[row][n-1]);
          for (col = 0; col < n-1; col++)
          {
                  printf("   *");
          }
          printf ("   \n");
          if (row != m-1) {
                  for (col = 0; col < n-1; col++)
                  {
                          printf("****");
                  }
                  printf ("***\n");
          }
  }
  printf("\n");

  return;
}

int is_valid (int m, int n, char board[][n], int row, int col)
{
	if(row >= 0 && row < m && col >= 0 && col < n){ // make sure row, col is within board to prevent segfaults
		if (board[row][col] == ' '){
			return 1;
		}
	}
	return 0;
}

int is_point (int m, int n, char board[][n], int row, int col, char move)
{
	int points = 0;
	if (move == 'O') {
		if (row + 1 < m && row - 1 >= 0) {
			if (board[row+1][col] == 'S' && board[row-1][col] == 'S'){
				points++;
			}
		}
		if (col + 1 < n && col - 1 >= 0) {
			if (board[row][col+1] == 'S' && board[row][col-1] == 'S') {
				points++;
			}
		}
		if (col + 1 < n && col - 1 >= 0 && row + 1 < m && row - 1 >= 0) {
			if (board[row+1][col+1] == 'S' && board[row-1][col-1] == 'S'){
				points++;
			}
			if (board[row+1][col-1] == 'S' && board[row-1][col+1] == 'S'){
				points++;
			}
		}
	}
	else if (move == 'S') {
		if (row-2 >= 0){
			if (board[row-1][col] == 'O' && board[row-2][col] == 'S') {
				points++;
			}
		}
		if (row+2 < m) {
			if (board[row+1][col] == 'O' && board[row+2][col] == 'S') {
				points++;
			}
		}
		if (col-2 >= 0) {
			if (board[row][col-1] == 'O' && board[row][col-2] == 'S') {
				points++;
			}
		}
		if (col+2 < n) {
			if (board[row][col+1] == 'O' && board[row][col+2] == 'S') {
				points++;
			}
		}
		if (row-2 >= 0 && col-2 >=0){
			if (board[row-1][col-1] == 'O' && board[row-2][col-2] == 'S') {
				points++;
			}
		}
		if (row+2 < m && col+2 < n) {
			if (board[row+1][col+1] == 'O' && board[row+2][col+2] == 'S') {
				points++;
			}
		}
		if (row+2 < m && col-2 >= 0) {
			if (board[row+1][col-1] == 'O' && board[row+2][col-2] == 'S'){
				points++;
			}
		}
		if (row-2 >= 0 && col+2 < n) {
			if (board[row-1][col+1] == 'O' && board[row-2][col+2] == 'S') {
				points++;
			}
		}
	}
	return points;
}

int board_full(int m, int n, char board[][n])
{
	for (int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

void print_points (char p1, char p2, int *p1_point, int *p2_point)
{
	if (p1 == 'c'){
		printf ("The computer has %d points!\n", *p1_point);
		printf ("The human has %d points!\n", *p2_point);
	}
	else if (p2 == 'c'){
		printf ("The computer has %d points!\n", *p2_point);
		printf ("The human has %d points!\n", *p1_point);
	}
	else {
		printf ("Player1 has %d points!\n", *p1_point);
		printf ("Player2 has %d points!\n", *p2_point);
	}
}

int play_again() {
	char c;
	do{
		while(getchar() != '\n'); // eat anything remaining up to and including the newline
		printf("Do you want to play again? (y/n): ");
		c = getchar();
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N');
	if (c == 'y' || c == 'Y') {
		return 1;
	}
	return 0;
}
