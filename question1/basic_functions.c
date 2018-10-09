#include <stdio.h>

/* Make sure board starts off empty. */
void init_board(char board[10][10])
{
  int row, col;

  for (row = 0; row < 10; row++)
    for (col = 0; col < 10; col++)
      *(*(board+row)+col) = ' ';

  return;
}

/* Display the board to standard output. */
void draw_board(int n, char board[10][10])
{
  int row, col;

  printf("\n");
  for (row = 0; row < n; row++)
  {
          for (col = 0; col < n-1; col++)
          {
                  printf("   *");
          }
          printf ("   \n");
          for (col = 0; col < n-1; col++)
          {
                  printf(" %c *", *(*(board+row)+col));
          }
          printf (" %c \n", *(*(board+row)+n-1));
          for (col = 0; col < n-1; col++)
          {
                  printf("   *");
          }
          printf ("   \n");
          if (row != n-1) {
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

/*
 * Ask if user wants tournament mode.
 * Returns the number of games to play if yes, 0 if no.
 */
int mode_check(void)
{
  char response;
  int c;
  printf("Do you want to play in tournament mode? (y/n) ");
  do
  {
    response = getchar();
  } while ((response != 'y') && (response != 'Y') &&
           (response != 'n') && (response != 'N'));
  getchar(); //eat the return

  if ((response == 'y') || (response == 'Y')){
    int n = 0;
    while (n == 0)
    {
      printf("How many games do you want to play? ");
      while ((c = getchar()) != '\n'){
        if (c >= '0' && c <= '9'){
                n = n*10 + c - '0';
        }
        else{
          n = 0;
          while((c = getchar()) != '\n'); //eat all additional characters
          break;
        }
      }
     }
    return n;
  }
  else
    return 0;
}


/*
 * Ask if user wants to go first.
 * Returns 1 if yes, 0 if no.
 */
int user_first(void)
{
  char response;

  printf("Do you want to go first? (y/n) ");
  do
  {
    response = getchar();
  } while ((response != 'y') && (response != 'Y') &&
           (response != 'n') && (response != 'N'));

  if ((response == 'y') || (response == 'Y'))
    return 1;
  else
    return 0;
}

/*
 * Ask if user wants to play again.
 * Returns 1 if yes, 0 if no.
 */
int play_again(void)
{
  char response;

  printf("Do you want to play again? (y/n) ");
  do
  {
    response = getchar();
  } while ((response != 'y') && (response != 'Y') &&
           (response != 'n') && (response != 'N'));

  if ((response == 'y') || (response == 'Y'))
    return 1;
  else
    return 0;
}

/* Check if the given symbol has already won the game. */
int symbol_won(char symbol, int n, char board[10][10])
{
  int row, col;
  int m = 0;

  for (row = 0; row < n; row++){
          for (col = 0; col< n; col ++){
                  if ((col + 2) < n){
                            if ((board[row][col] == symbol) &&
                                (board[row][col+1] == symbol) &&
                                (board[row][col+2] == symbol))
                            return 1;
                  }
                  if (row + 2 < n){
                            if ((board[row][col] == symbol) &&
                                (board[row + 1][col] == symbol) &&
                                (board[row + 2][col] == symbol))
                            return 1;
                  }
                  if ((row + 2 < n) && (col + 2 < n)){
                            if ((board[row][col] == symbol) &&
                                (board[row + 1][col + 1] == symbol) &&
                                (board[row + 2][col + 2] == symbol))
                            return 1;
                  }
                  if ((row + 2 < n) && (col - 2 >= 0)){
                            if ((board[row][col] == symbol) &&
                                (board[row + 1][col - 1] == symbol) &&
                                (board[row + 2][col - 2] == symbol))
                            return 1;
                  }
          }
  }
  return 0;
}


