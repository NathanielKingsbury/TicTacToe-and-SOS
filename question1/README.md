## Question 1

Extend the tic-tac-toe game that we went over in class with the following additional requirements:
* Split up the program into multiple logical .c and .h files.
* Create a make file in order to compile the game.
* Keep track of how many wins the player and the computer won for the duration of the program.
* Allow a user to specify a tournament mode where the winner is determined by winning the best out of x games.

This question is 50 points (25 pts for quality & 25 pts for output).

Bonus (+10 for each): 
* Allow a user to specify the board to nxn.
* Modify the win condition to check for 3 X's or 3 O's in a row, column, or diagonal in the nxn tic-tac-toe board.
* Modify the computer_move function to play more intelligently on a 4x4 or 5x5 board.


Compile Steps:
To compile the program, simply type the command "make". To run it, use "./TicTacToe.exe".

Sample Output:

What size board would you like to play on? Please enter a number between 3 and 9, inclusive: 3
Do you want to play in tournament mode? (y/n) n
Do you want to go first? (y/n) y
Enter a square: 1

   *   *
 X *   *
   *   *
***********
   *   *
   *   *
   *   *
***********
   *   *
   *   *
   *   *


I am choosing square 5!

   *   *
 X *   *
   *   *
***********
   *   *
   * O *
   *   *
***********
   *   *
   *   *
   *   *

Enter a square: 9

   *   *
 X *   *
   *   *
***********
   *   *
   * O *
   *   *
***********
   *   *
   *   * X
   *   *


I am choosing square 7!

   *   *
 X *   *
   *   *
***********
   *   *
   * O *
   *   *
***********
   *   *
 O *   * X
   *   *

Enter a square: 3

   *   *
 X *   * X
   *   *
***********
   *   *
   * O *
   *   *
***********
   *   *
 O *   * X
   *   *


I am choosing square 6!

   *   *
 X *   * X
   *   *
***********
   *   *
   * O * O
   *   *
***********
   *   *
 O *   * X
   *   *

Enter a square: 2

   *   *
 X * X * X
   *   *
***********
   *   *
   * O * O
   *   *
***********
   *   *
 O *   * X
   *   *


Congratulations, you win!

Computer: 0
Player: 1
Draws:0
Do you want to play again? (y/n) n


