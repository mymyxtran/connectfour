#include "./game.h"


Game::Game(int row, int col, char player_1, char player_2){
	/* Constructor contructs game using input (row_of_game_board, col_of_game_board, player_1 char_identifier, player_2_char_identifier) */
	max_row = row;
    max_col = col;
    /* Default player 1 goes first */
    p1 = player_1;
    p2 = player_2;
    active_player = player_1;
    inactive_player = player_2;
    /* Allocate dynamic memory for this board */
    board = new char*[max_row];
    for(int i = 0; i < max_row; ++i)
        board[i] = new char[max_col];
    /* Initialize values for board */
    for(int row = 0; row < max_row; ++row){
		for(int col = 0; col < max_col; ++col){
			board[row][col] = '0';
		}
   }
}

Game::~Game(){
	/* Free that memory you allocated during the creation of this class */
	for(int i = 0; i < max_row; ++i)
			delete[] board[i];
	delete [] board;
}

void Game::play(){
	/* Store user input in column and buffer */
	int column;
	string buffer;

	/* Print Instructions */
	cout << "Welcome to ConnectFour!" <<endl;
	cout << "Instructions: " << endl <<"Player 1 is " << "(" << p1 << ")" << " and Player 2 is " << "(" << p2 << ")" << endl;
	cout << "This is your "  <<max_row << " x " << max_col << " game board. To indicate which column you would like to place your chip, "
			"enter the respective column number." << endl;
	print_board();
	cout << "Press any key to begin the game!" <<endl << ">>";
	cin >> buffer;
	cout << "Beginning the game!" <<endl;

	/* Play game while there is no winner! */
	/* Case 1: Begin game, so empty board, so no winner.
	 * Case 2: The previous player who just went is now inactive, check if they made a move that made them win
	 * Case 3: Tie! The board is filled and there is no winner!
	 */
	while ( !winner(inactive_player) && !tie() ){
		if (active_player == p1) {
			cout << "Player 1's move: " << endl << ">>";
			cin >> column;
		} else {
			cout <<"Player 2's move: " << endl << ">>";
			cin >> column;
		}
		/* Prompt for valid entry! Invalid entry is when a selected column is filled! */
		while(!valid_move(column)){
			cout << "Enter a valid column: " <<endl << ">>";
			cin >> column;
		}
		/* Update game board and print board to show active player new move */
		update_board(column);
		print_board();
		/* Update the active player */
		swap_active_player();
	}
	print_result();
	return;
}

void Game::update_board(int col){
	int row = max_row-1;
	bool updated = false;
	while(row >=0 && updated == false){
		if( board[row][col] == '0'){
			board[row][col] = active_player ;
			updated = true;
		}
		row--;
	}
	return;
}

bool Game::valid_move(int col){
	/*check to see if the column has an empty space*/
	int row = max_row-1;
	while(row >=0){
		if( board[row][col] == '0'){
			return true;
		}
		row--;
	}
   return false;
}
void Game::swap_active_player(){
	char temp = active_player;
	active_player = inactive_player;
	inactive_player = temp;
	return;
}

bool Game::winner(char player) {
	/* Check for winner in all directions for eachposition row, col */
    for(int row = 0 ; row < max_row ; row++){
    	for(int col = 0 ; col < max_col ; col++){
		bool result = find_winner(player, row, col, 1, 0) ||
				find_winner(player, row, col, -1, 0) ||
				find_winner(player, row, col, 0, 1) ||
				find_winner(player, row, col, 0, -1) ||
				find_winner( player, row, col, 1, 1) ||
				find_winner( player, row, col, -1, -1) ||
				find_winner( player, row, col, -1, 1) ||
				find_winner( player, row, col, 1, -1);
		if(result)
			return true;
    	}
    }
    return false; // a winner was not found
}

/* Return if winner found*/
bool Game::find_winner(char player, int row, int col, int rowDelta, int colDelta) {
	bool match = false;
	int matches = 0;
	while (row < max_row && row >= 0 && col < max_col && col >= 0) {
		int temp = board[row][col];
		if (temp != player && match) {
			break;
		} else if (temp == player) {
			match = true;
			matches++;
		}
		row += rowDelta;
		col += colDelta;
	}
	return matches == 4;
}

bool Game::tie(){
	for(int row = 0 ; row < max_row ; row++){
		for(int col = 0 ; col < max_col ; col++){
			/* There is still an empty space, so the board is not full and there is no tie. */
			if(board[row][col] == '0')
				return false;
		}
	}
	return true;
}

void Game::print_board(){
	/* print --- for board borders */
	for(int col = 0; col < max_col; ++col){
			cout << "----";
	}
	cout << endl;
	for(int row = 0; row < max_row; ++row){
		/* print each element row*/
		cout << "| ";
		for(int col = 0; col < max_col; ++col){
			cout << board[row][col] << " | ";
		}
		cout << endl;
		/*Print lines between rows*/
		for(int col = 0; col < max_col; ++col){
			cout << "----";
		}
		cout << endl;
	}

	/* Print respective col numbers at bottom of the board */
	for(int col = 0; col < max_col; ++col){
		cout << "----";
	}
	cout << endl;
	cout << "| ";
	for(int col = 0; col < max_col; ++col){
		cout << col << " | ";
    }
	cout <<endl; // End all prints with endl
	return;
}

void Game::print_result(){
	if(tie()){
		cout << "Tie game!" << endl;
	}else{
		if(inactive_player == 'R'){
				cout << "Winner is: Player 1 (R)" << endl;
		} else{
			cout << "Winner is: Player 2 (B)" << endl;
		}
	}
}

