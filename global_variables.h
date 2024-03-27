#pragma once
#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES
#include "functions.h"

extern int bestMoveI = { -1 };
extern int bestMoveJ = { -1 };
extern bool turn = 0;
extern int playerScore1 = {0};
extern int playerScore2 = {0};
extern char player1sign = {};
extern char player2sign = {};
extern std::string player1name = {};
extern std::string player2name = {};
extern char currentPlayer = {};
extern int turnNumber = {};
#endif // GLOBAL_VARIABLES
