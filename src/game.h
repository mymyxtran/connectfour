/*
 * game.h
 *
 *  Created on: Nov. 14, 2020
 *      Author: mymytran
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <stdlib.h>
#include <string>
#include "stdbool.h"
#include "string.h"

using namespace std;

class Game{
private:
	/* Board Size */
    int max_row;
    int max_col;
public:
    /* Game characteristics */
    char **board;
    char p1, p2;
    char active_player;
    char inactive_player;
    void play();
    /* Logic functions */
    void swap_active_player();
    void update_board(int col);
    bool valid_move(int col);
    bool winner(char player);
    bool find_winner(char player, int row, int col, int rowDelta, int colDelta);
    bool tie();
    /* Print board */
    void print_board();
    void print_result();

    /* Constructors & Deconstructors */
	Game(int row, int col, char player_1, char player_2);
    ~Game(); // Need to declare our own to free dynamic memory
};

#endif /* GAME_H_ */
