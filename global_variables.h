#pragma once
#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES

char board[100][100];
extern int lastTurnI = {};
extern int lastTurnJ = {};
extern int bestMoveI = { -1 };
extern int bestMoveJ = { -1 };
extern bool turn = 0;
extern int playerScore1 = { 0 };
extern int playerScore2 = { 0 };
extern char player1sign = {};
extern char player2sign = {};
extern std::string player1name = {};
extern std::string player2name = {};
extern char currentPlayer = {};
extern int turnNumber = {};
extern int tableHeight = {};
extern int tableLength = {};
extern int winningLength = {};

//i pulled it of the internet here, i didnt know about vectors in programming ( only those int smth[1132])
//i still dont fully grasp the syntax but i understood that its making a vector , with vector as elements bassically
//and they initialise the vector with ' ' for tableHeight by tableLegth
// vector<vector elements which are others vector<of type char>> named board(with these many vectors, and each vector<that is char>(has these many elements))
// so a hypothethical 3D would look lke 
//std::vector<std::vector<std::vector<char>>> CUBE(tableHeight, std::vector<std::vector<char>>(tableLength, std::vector<char>(tableWideness, ' ');
//std::vector<std::vector<std::vector<std::vector<int>>>> 4D(1d, std:vector<std::vector<std::vector<int>>>(2D,std::vector<std::vector<int>>(3D, std::vector<int>(4D, 0)))
//ok i think ive got it
//std::vector<std::vector<char>> board(tableHeight, std::vector<char>(tableLength, ' '));
//Im sorry it keeps giving me an error that it is out of bounds , i dont understand why it starts normally than it crashes my whole visual studio.

#endif // GLOBAL_VARIABLES
