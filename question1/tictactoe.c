/*
 * This program plays Tic-Tac-Toe against the user!
 * The program uses a specified, not-perfect strategy.
 * The code uses only basic programming concepts.
 * Written by: Carl Sable
 * Extended by: Nathaniel Kingsbury
 */

#include <stdio.h>
#include <basic_functions.h>
#include <computer_moves.h>
#include <player_moves.h>

int play_game(int, char, char, char board[10][10]);

/* 
 * Initialize the board, ask who goes first, play a game,
 * ask if user wants to play again.
 */
int main(void)
{
  char board[10][10];
  int n = 0;
  char c, user, computer;
  do {
    printf("What size board would you like to play on? Please enter a number between 3 and 9, inclusive: ");
    n = getchar() - '0';
    while ((c = getchar()) != '\n'); // eat anything extra up to the newline
    if (n < 3 || n > 9){
	    printf ("Invalid choice\n");
	    n = 0;
    }
  } while (!n);
  int mode = mode_check();
  int player_wins, comp_wins, draws, games_played = 0;
  int winner;
  while(1)
  {
    init_board(board);
    if (user_first())
    {
      computer = 'O';
      user = 'X';
    }
    else
    {
      computer = 'X';
      user = 'O';
    }
    winner = play_game(n, user, computer, board);
    games_played++;
    if (winner == 1){
	    comp_wins++;
    }
    else if (winner == 2){
	    player_wins++;
    }
    else if (winner == 0){
	    draws++;
    }
    printf("Computer: %d\nPlayer: %d\nDraws:%d\n", comp_wins, player_wins, draws);
    if (!mode){
      if (!play_again())
        break;
    }
    if (games_played == mode){
      if (comp_wins > player_wins){
	      printf("I WIN THE TOURNAMENT!!!!!!!!");
      }
      else if (player_wins > comp_wins){
	      printf("Congradulations, you win the tournament");
      }
      else{
	      printf("The tournament is a draw.");
      }
      break;
    }
  }
  return 0;
}

/* Loop through 9 turns or until somebody wins. */
int play_game(int n, char user, char computer, char board[10][10])
{
  int turn;

  for (turn = 1; turn <= n*n; turn++)
  {
    /* Check if turn is even or odd 
       to determine which player should move. */
    if (turn % 2 == 1)
    {
      if (computer == 'X')
        computer_move(n, user, computer, board);
      else
        player_move(n, user, board);
    }
    else
    {
      if (computer == 'O')
        computer_move(n, user, computer, board);
      else
        player_move(n, user, board);
    }

    draw_board(n, board);

    if (symbol_won(computer, n, board)) {
      printf("\nI WIN!!!\n\n");
      return 1;
    }
    else if (symbol_won(user, n, board)) {
      printf("\nCongratulations, you win!\n\n");
      return 2;
    }
  }

  printf("\nThe game is a draw.\n\n");
  return 0;
}
