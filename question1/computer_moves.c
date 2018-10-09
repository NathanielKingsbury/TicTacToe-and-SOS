#include <stdio.h>
#include <basic_functions.h>

/*
 * Find a win, if any, for the given symbol.
 * If a winning square exists, return the square;
 * otherwise, return 0.
 */
int find_win(char symbol, int n, char board[10][10])
{
  int square, row, col;
  int result = 0;

  /*
   * Loop through the n^2 squares.
   * For each, if it is empty, fill it in with the given
   * symbol and check if this has resulted in a win.
   * If so, keep track of this square in result.
   * Either way, reset the square to empty afterwards.
   * After the loop, if one or more wins have been found,
   * the last will be recorded in result.
   * Otherwise, result will still be 0.
   */
  for (square = 1; square <= n*n; square++)
  {
    row = (square - 1) / n;
    col = (square - 1) % n;

    if (board[row][col] == ' ')
    {
      board[row][col] = symbol;
      if (symbol_won(symbol, n, board))
        result = square;
      board[row][col] = ' ';
    }
  }

  return result;
}

/* Find a square, if any, for the given symbol such that on the following turn, that symbol is guaranteed to win
 * (i.e. such that choosing this square leads to two possible routes to victory for the given  symbol)
 * If this square exists, return it; otherwise, return 0
 */
int plan_win(char symbol, int n, char board[10][10])
{
        int square, square2, row, row2, col, col2;
        int result = 0;
        int m = 0;
        for (square = 1; square<=n*n; square++)
        {
                row = (square - 1)/n;
                col = (square - 1)%n;
                if (board[row][col] == ' ')
                {
                        board[row][col] = symbol;
                        for (square2 = 1; square2 <= n*n; square2++){
                                row2 = (square2 - 1)/n;
                                col2 = (square2 - 1)%n;
                                if (board[row2][col2] == ' ')
                                {
                                        board[row2][col2] = symbol;
                                        if (symbol_won(symbol, n, board))
                                                m++;
                                        board[row2][col2] = ' ';
                                }
                        }
                        if (m > 1){
                                result = square;
                        }
                        board[row][col] = ' ';
                        m = 0;
                }
        }
        return result;
}

/*
 * If a middle square is empty, return it;
 * otherwise return 0.
 */
int middle_open(int n, char board[10][10])
{
        int row = ((n-1)/2);
        int col = ((n-1)/2);
        if (board[row][col] == ' ')
                return (row*n + col + 1);
        if (!(n % 2)) // if n is even, check for additional middles
        {
                row++;
                if (board[row][col] == ' ')
                        return (row*n + col + 1);
                col++;
                if (board[row][col] == ' ')
                        return (row*n + col + 1);
                row--;
                if (board[row][col] == ' ')
                        return (row*n + col + 1);
        }
        return 0;
}

/*
 * Return the number of an empty corner, if one exists;
 * otherwise return 0.
 */
int find_corner(int size, int radius, char board[10][10])
{
  int coord1 = (size-1)/2 - radius; //one possible row or column coord a corner of the given radius from the center of the nXn board
  int coord2 = (size-1)/2 + ((size+1)%2) + radius; // the other possible coord
  if (board[coord1][coord1] == ' ')
    return coord1*size + coord1 + 1;
  if (board[coord1][coord2] == ' ')
    return coord1*size + coord2 + 1;
  if (board[coord2][coord1] == ' ')
    return coord2*size + coord1 + 1;
  if (board[coord2][coord2] == ' ')
    return coord2*size + coord2 + 1;

  return 0;
}

/*
 * Return the number of an empty side square, if one exists;
 * otherwise return 0.
 */
int find_side(int size, int radius, char board[10][10])
{
  int coord1 = (size-1)/2 - radius;
  int coord2 = (size-1)/2 + ((size+1)%2) + radius;
  int i;
  for (i = coord1 + 1; i < coord2; i++)
  {
          if (board[coord1][i] == ' ')
          {
                  return coord1*size + i + 1;
          }
          if (board[i][coord1] == ' ')
          {
                  return i*size + coord1 + 1;
          }
          if (board[coord2][i] == ' ')
          {
                  return coord2*size + i + 1;
          }
          if (board[i][coord2] == ' ')
          {
                  return i*size + coord2 + 1;
          }
  }
  return 0;
}

/* Choose a move for the computer. */
void computer_move(int n, char user, char computer, char board[10][10])
{
  int square;
  int row, col;
  int i = 1;

  /* Use first strategy rule that returns valid square */
  square = find_win(computer, n, board);
  if (!square)
  {
    square = find_win(user, n, board);
  }
  if (!square)
  {
    square = plan_win(computer, n, board);
  }
  if (!square)
  {
    square = plan_win(user, n, board);
  }
  if (!square)
  {
    square = middle_open(n, board);
  }
  while (!square) {
    square = find_corner(n, i, board);
    if (!square){
      square = find_side(n, i, board);
    }
    i++;
    if (i > ((n-1)/2)) // if i is out of bounds, and would start checking squares that aren't in the board
            break; //stop the loop
  }
  if (!square)
          printf("Things are very wrong. Please stop this program");
  printf("\nI am choosing square %d!\n", square);

  row = (square - 1) / n;
  col = (square - 1) % n;

  board[row][col] = computer;

  return;
}

