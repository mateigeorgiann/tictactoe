#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>
#include<utility>
#include<algorithm>
#include <vector>
#include "global_variables.h"


//update this function curently it does absolutely nothing
void endGame()
{

}

char modeOfPlay() {
    static char mode;
    while (true)
    {
        system("cls");
        std::cout << "Do you want to play single player or multiplayer ? Press S or M :";
        mode = _getch();
        if (mode == 'S' || mode == 'M') {
            system("cls");
            return mode;
        }
    }
}

//init board with ' '

void createBoard()
{
    for (int i = 0; i < tableHeight; i++)
        for (int j = 0; j < tableLength; j++)
            board[i][j] = ' ';
}

//clear cin in case of missinput from player
void clearCIN()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

//draw the board/game
void draw()
{
   
    
    std::cout << "     TIC-TAC-TOE     \n\n";
    //Apparently i think there is a limit to consoles cause for heght it can draw more than like 6 levels even if it tries , same or length at about 30
    std::cout << '\n';
    int j;
    for (j=0; j < tableHeight; j++) {
        for (int i=0; i < tableLength-1; i++) {
            std::cout << "   |";
        }
        std::cout << '\n'<<" ";
        int l;
        for (l=0; l < tableLength-1; l++)
        {
            std::cout<< board[j][l] << " | ";
        }
        l=tableHeight-1;
        std::cout << board[j][l];
        std::cout << '\n';
        for (int i=0; i < tableLength-1; i++) {
            std::cout << "   |";
        }
        if (j < tableLength - 1) {
            std::cout << "\n---+";
            for (int k = 0; k < tableLength-2; k++)
                std::cout << "---+";
            std::cout << "---\n";
        }
    }
}

//check if its a draw
bool drawGame(int& turnNumber)
{
    if (turnNumber == tableHeight*tableHeight) {

        return true;
    }
    return false;
}

//check winning condition
bool checkWinning(char currentPlayer)
{
    char currentBoard;
    int index = 1;
    //this is length wise
    //copy last i, j in c_i , c_j , the next 2 fors is checking right and then left
    int c_j, c_i;
    for (c_j = lastTurnJ + 1; c_j <= lastTurnJ + winningLength + 1; c_j++) {

        if (board[lastTurnI][c_j] == board[lastTurnI][lastTurnJ]) {
            index++;

        }
        else
            break;
    }
    for (c_j = lastTurnJ - 1; c_j >= lastTurnJ - winningLength - 1; c_j--) { //you changed last turn I in case everything breaks
        if (board[lastTurnI][c_j] == board[lastTurnI][lastTurnJ]) {
            index++;

        }
        else
            break;
    }
    if (index == winningLength)
        return true;

    index = 1; //reset in case it didnt find anything horizontally

    //for vertical checking
           for (c_i = lastTurnI + 1; c_i <= lastTurnI + winningLength + 1; c_i++) {

               if (board[c_i][lastTurnJ] == board[lastTurnI][lastTurnJ]) {
                   index++;

               }
               else
                   break;
           }
       for (c_i = lastTurnI - 1; c_i >= lastTurnI - winningLength - 1; c_i--) {
           if (board[c_i][lastTurnJ] == board[lastTurnI][lastTurnJ]) {
               index++;

           }
           else
               break;
       }
       if (index == winningLength)
           return true;

       index = 1;
       //1ST DIAGONAL
       //
       for (c_j = lastTurnJ + 1; c_j <= lastTurnJ + winningLength + 1; c_j++) {

           if (board[lastTurnI + c_j][c_j] == board[lastTurnI][lastTurnJ]) {
               index++;

           }
           else
               break;
       }
       for (c_j = lastTurnJ - 1; c_j >= lastTurnJ - winningLength - 1; c_j--) { //you changed last turn I in case everything breaks
           if (board[lastTurnI - c_j][c_j] == board[lastTurnI][lastTurnJ]) {
               index++;

           }
           else
               break;
       }
       if (index == winningLength)
           return true;

       index = 1;
       //for 2ND diagonal checking
       for (c_j = lastTurnJ + 1; c_j <= lastTurnJ + winningLength + 1; c_j++) {

           if (board[lastTurnI-c_j][c_j] == board[lastTurnI][lastTurnJ]) {
               index++;

           }
           else
               break;
       }
       for (c_j = lastTurnJ - 1; c_j >= lastTurnJ - winningLength - 1; c_j--) { //you changed last turn I in case everything breaks
           if (board[lastTurnI+c_j][c_j] == board[lastTurnI][lastTurnJ]) {
               index++;

           }
           else
               break;
       }
       if (index == winningLength)
           return true;



       index = 1;

       return 0;
}


   




//mimax alg
int minimax(char currentPlayer, int turnNumber)
{
    //check if its a final move
    if (checkWinning(currentPlayer))
        if (currentPlayer == 'X')
            return 1;
        else
            return -1;
    if (drawGame(turnNumber))
        return 0;

    //the ai player will be player 2
    int bestScore = (player2sign == currentPlayer) ? -10 : 10;

    //goes trough all moves
    for (int i = 0; i <tableHeight; i++)
        for (int j = 0; j <tableLength; j++)
        {
            static int score;
            if(turnNumber<=9)
            if (board[i][j] == ' ')
            {
                board[i][j] = currentPlayer;
                score = minimax((currentPlayer == 'X') ? 'O' : 'X', turnNumber + 1);
                board[i][j] = ' ';

            }

            if (currentPlayer == player2sign)
                bestScore = std::max(bestScore, score);
            else
                bestScore = std::min(bestScore, score);
        }

    return bestScore;
}

//ai decides whats the best move
void bestMoveAI(int& bestMoveI, int& bestMoveJ, int turnNumber)//i couldnt figure out without looking at more 
//resources online how to do it, i know there was a pair function , or do it with a struct but that mean i had to take a lot of things
//from 0, next time ill plan even better ahead
{

    bestMoveI = -1;
    bestMoveJ = -1;
    int bestScore = -10;
    int i, j;
    for (i = 0; i < tableHeight; i++)
        for (j = 0; j < tableLength; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = currentPlayer;
                int score = minimax(currentPlayer, turnNumber);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    bestMoveI = i;
                    bestMoveJ = j;
                }
            }
        }


}

//sets names for singleplayer
void setNames()
{
    playerScore1 = { 0 };
    playerScore2 = { 0 };
    std::cout << "Enter player 1 name: ";
    std::cin >> player1name;
    clearCIN();
    std::cout << "\nEnter player 2 name: ";
    std::cin >> player2name;
    clearCIN();
}

//take turn function for AI
void takeTurn(char& currentPlayer, int turnNumber) {
    std::cout<<'\n' << currentPlayer << " is playing now\n";
    //waits for valid move input
    while (true)
    {
        int i = -1;
        int j = -1;
        if (((player1sign == currentPlayer) && (player1name != "AI")) || ((player2sign == currentPlayer) && (player2name != "AI"))) {
            std::cin >> i >> j;
        }
        else
        {
            bestMoveAI(bestMoveI, bestMoveJ, turnNumber);
            i = bestMoveI;
            j = bestMoveJ;
        }
        if (i >= 0 && i < tableHeight && j>=0 && j < tableLength && board[i][j] == ' ') {
            board[i][j] = currentPlayer;
            lastTurnI = i;
            lastTurnJ = j;
            break;
        }
        std::cout << "\nIllegal move\n";
        clearCIN();
    }
    //changes player turn
    if (currentPlayer == 'O')
    {
        currentPlayer = 'X';
    }
    else {
        currentPlayer = 'O';
    }
}

//its multiplayer
void playSinglePlayer()
{
    createBoard();

    system("cls");


    if (turn) {
        std::cout << player1name << " plays as X\n" << player2name << " plays as O\n";
        player1sign = 'X';
        player2sign = 'O';
    }
    else
    {
        std::cout << player2name << " plays as X\n" << player1name << " plays as O\n";
        player1sign = 'O';
        player2sign = 'X';
    }
    currentPlayer = 'X';
    turnNumber = 1;
    while (turnNumber <= tableLength*tableHeight)
    {
        draw();
        takeTurn(currentPlayer, turnNumber);
        //you cant win in less than the number of winningLength -1 , its logic , classical tictactoe is 3*2-1 which is 5.
        if (turnNumber >= winningLength*2-1) {

            //i now realised that i dont need at all any arguments for checkWinning
            if (checkWinning(currentPlayer))
            {
                //YOU INITIALLY F UP , AND ALSO IF YOU CANT FIGURE OUT WHY ITS ?REVERSED , ITS BECAUSE IN TAKE TURN I ALREADY SWITCH THE CURRENT PLAYER SO HERE IT CHECKS THE OTHER PLAYER SAME FOR DOWN BELOW

                std::cout << (currentPlayer == player2sign ? player1sign : player2sign)
                    << " has won!" << "\n\nFinal Score : \n";
                if (player2sign == currentPlayer)
                    playerScore1++;
                else
                    playerScore2++;
                //if there is a winner it will be anounced
                std::cout << player1name << " has " << playerScore1 << " points \n \n";
                std::cout << player2name << " has " << playerScore2 << " points \n \n";

                break;

            }
        }
        if (drawGame(turnNumber)) {
            std::cout << "It's a DRAW";
            break;
        }
        turnNumber++;
        system("cls");
    }
}

//its single player 
void playMultiPlayer()
{



    createBoard();
    if (turn) {
        std::cout << player1name << " plays as X\n" << player2name << " plays as O\n";
        player1sign = 'X';
        player2sign = 'O';
    }
    else
    {
        std::cout << player2name << " plays as X\n" << player1name << " plays as O\n";
        player1sign = 'O';
        player2sign = 'X';
    }
    currentPlayer = 'X';
    turnNumber = 1;



    while (turnNumber <= tableHeight*tableLength)
    {
        draw();
        takeTurn(currentPlayer, turnNumber);
        //you cant win in less than the number of winningLength -1 , its logic , classical tictactoe is 3*2-1 which is 5.
        if (turnNumber >= winningLength*2-1) {

            //i now realised that i dont need at all any arguments for checkWinning
            if (checkWinning(currentPlayer))
            {
                //YOU INITIALLY F UP , AND ALSO IF YOU CANT FIGURE OUT WHY ITS ?REVERSED , ITS BECAUSE IN TAKE TURN I ALREADY SWITCH THE CURRENT PLAYER SO HERE IT CHECKS THE OTHER PLAYER SAME FOR DOWN BELOW
                system("cls");
                std::cout << (currentPlayer == player2sign ? player1sign : player2sign)
                    << " has won!" << "\n\nFinal Score : \n";
                if (player2sign == currentPlayer)
                    playerScore1++;
                else
                    playerScore2++;
                //if there is a winner it will be anounced
                std::cout << player1name << " has " << playerScore1 << " points \n \n";
                std::cout << player2name << " has " << playerScore2 << " points \n \n";

                break;

            }
        }
        if (drawGame(turnNumber)) {
            std::cout << "It's a DRAW";
            break;
        }
        turnNumber++;
        system("cls");
    }
}


//ask size for the table dimensions and for the winning condition
void askSizes() {
    
        std::cout << "Choose a table height, length, and winning condition. For example : 3 3 3(classic) OR 4 5 2\n";
        while (true) {
            std::cin >> tableHeight;
            if (!std::cin || tableHeight<1)
            {
                std::cout << "WRONG !\n\n ENTER THE TABLE HEIGHT AGAIN!";
                clearCIN();
            }
            else { break; }
        }
        while (true) {
            std::cin >> tableLength;
            if (!std::cin || tableHeight <1)
            {
                std::cout << "WRONG !\n\n ENTER THE TABLE LENGTH AGAIN!";
                clearCIN();
            }
            else { break; }
        }
        while (true) {
            std::cin >> winningLength; //this little thing was overeading the tablelength aka no winninlength . took me 1 hour to fix this and some other small bugs shoot myself 
            if (!std::cin)
            {
                std::cout << "WRONG !\n\n ENTER THE TABLE LENGTH AGAIN!";
                clearCIN();
            }
            else { break; }
        }
        /*
        board.resize(tableHeight+1);
        for(int i=0;i<tableHeight;i++)
        {
            board[i].resize(tableLength+1, ' ');
        }
        */
}



#endif

//DONT FORGET ABOUT VERIFYING DRAWS , FULL MAP , P1 WINS , P 2 WINS , ALSO WITH AI  chechl=
//CLEAN UP SCREEEN  AFTER GAME check
// 
// CLEAN UP WHEN INVALID INPUT check
//EAT A TREAT CAUSE U MANAGED About to do
