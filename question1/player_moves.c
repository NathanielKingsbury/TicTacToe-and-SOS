/* Check if the given square is valid and empty. */
int square_valid(int square, int n, char board[10][10])
{
  int row, col;

  row = (square - 1) / n;
  col = (square - 1) % n;

  if ((square >= 1) && (square <= n*n))
  {
    if (board[row][col] == ' ')
      return 1;
  }

  return 0;
}

/* Have the user choose a move. */
void player_move(int n, char user, char board[10][10])
{
  int square;
  int row, col;

  do
  {
    printf("Enter a square: ");
    scanf("%d", &square);
  } while (!square_valid(square, n, board));

  row = (square - 1) / n;
  col = (square - 1) % n;

  board[row][col] = user;

  return;
}


