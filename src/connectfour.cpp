//============================================================================
// Name        : connectfour.cpp
// Author      : Mymy Tran
// Version     : 1
//============================================================================

#include <iostream>
#include "game.h"
using namespace std;

int main() {
	/* Create instance of game*/
	/* Default Player 1 = 'R' goes first, Player 2 = 'B' goes second */
	/* Default: Commonly used Connect Four board: rows = 6, columns = 7 */
	/* Constructor contructs game using input (row_of_game_board, col_of_game_board, player_1 char_identifier, player_2_char_identifier) */
	Game game(6, 7, 'R', 'B');

	/* Start playing an instance of the game! */
	game.play();
	return 0;
}

