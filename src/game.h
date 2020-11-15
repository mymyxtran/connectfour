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

    /* Logic functions */
    void play();
    bool isPlaying(); // required func
    char getWinner(); // required fun
    void pickColumn(char player, int col); // required fun
    void swapActivePlayer();
    bool validMove(int col);
    bool winner(char player);
    bool findWinner(char player, int row, int col, int rowDelta, int colDelta);
    bool tie();
    /* Print board */
    void printBoard();
    void printResult();

    /* Constructors & Deconstructors */
	Game(int row, int col, char player_1, char player_2);
    ~Game(); // Need to declare our own to free dynamic memory
};

#endif /* GAME_H_ */
