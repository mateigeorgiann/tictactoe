#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>
#include<utility>
#include<algorithm>
#include <vector>
#include "global_variables.h"

    char board[4][4];
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
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
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
        std::cout << "       |   |\n";
        std::cout << "    " << board[1][1] << "  " << "|" << " " << board[1][2] << " |  " << board[1][3] << '\n';
        std::cout << "       |   |" << '\n';
        std::cout << " ------+---+------" << '\n';
        std::cout << "       |   |\n";
        std::cout << "    " << board[2][1] << "  " << "|" << " " << board[2][2] << " |  " << board[2][3] << '\n';
        std::cout << "       |   |" << '\n';
        std::cout << " ------+---+------" << '\n';
        std::cout << "       |   |\n";
        std::cout << "    " << board[3][1] << "  " << "|" << " " << board[3][2] << " |  " << board[3][3] << '\n';
        std::cout << "       |   |" << '\n';
    }

    //check if its a draw
    bool drawGame(int& turnNumber)
    {
        if (turnNumber >=9) {
            
            return true;
        }
        return false;
    }
   
    //check winning condition
    bool checkWinning(char currentPlayer)
    {
        if (
               ((board[1][1] == board[1][2]) && (board[1][2] == board[1][3]) && (board[1][1] != ' '))
            || ((board[2][1] == board[2][2]) && (board[2][2] == board[2][3]) && (board[2][1] != ' '))
            || ((board[3][1] == board[3][2]) && (board[3][2] == board[3][3]) && (board[3][1] != ' '))
            || ((board[1][1] == board[2][1]) && (board[2][1] == board[3][1]) && (board[1][1] != ' '))
            || ((board[1][2] == board[2][2]) && (board[2][2] == board[3][2]) && (board[1][2] != ' '))
            || ((board[1][3] == board[2][3]) && (board[2][3] == board[3][3]) && (board[1][3] != ' '))
            || ((board[1][1] == board[2][2]) && (board[2][2] == board[3][3]) && (board[1][1] != ' '))
            || ((board[1][3] == board[2][2]) && (board[2][2] == board[3][1]) && (board[1][3] != ' '))
            )
            return true;
        else
            return false;
    }

    //mimax alg
    int minimax(char currentPlayer,int turnNumber)
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
        for(int i = 1;i<=3;i++)
            for (int j = 1; j <= 3; j++)
            {
                static int score;
                if (board[i][j] == ' ')
                {
                    board[i][j] = currentPlayer;
                    score = minimax((currentPlayer == 'X') ? 'O' : 'X', turnNumber+1);
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
   void bestMoveAI(int& bestMoveI, int& bestMoveJ,int turnNumber)//i couldnt figure out without looking at more 
       //resources online how to do it, i know there was a pair function , or do it with a struct but that mean i had to take a lot of things
       //from 0, next time ill plan even better ahead
    {
        
                bestMoveI = -1;
                bestMoveJ = -1;
        int bestScore = -10;
        int i, j;
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = currentPlayer;
                    int score = minimax(currentPlayer,turnNumber);
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
        std::cout << currentPlayer << " is playing now\n";
        //waits for valid move input
        while (true)
        {
            int i = -1 ;
            int j = -1 ;
            if (((player1sign == currentPlayer) && (player1name != "AI")) || ((player2sign == currentPlayer) && (player2name != "AI"))) {
                std::cin >> i >> j;
            }
            else
            {
                bestMoveAI(bestMoveI,bestMoveJ,turnNumber);
                i = bestMoveI;
                j = bestMoveJ;
            }
            if (i > 0 && i < 4 && j>0 && j < 4 && board[i][j] == ' ') {
                board[i][j] = currentPlayer;
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
        while (turnNumber <= 9)
        {
            draw();
            takeTurn(currentPlayer,turnNumber);
            //you cant win in less than 5 turns so we eliminate half of the comparasions 
            if (turnNumber >= 5) {

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
        


            while (turnNumber <= 9)
            {
                draw();
                takeTurn(currentPlayer, turnNumber);
                //you cant win in less than 5 turns so we eliminate half of the comparasions 
                if (turnNumber >= 5) {

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

#endif

    //DONT FORGET ABOUT VERIFYING DRAWS , FULL MAP , P1 WINS , P 2 WINS , ALSO WITH AI  chechl=
    //CLEAN UP SCREEEN  AFTER GAME check
    // 
    // CLEAN UP WHEN INVALID INPUT check
    //EAT A TREAT CAUSE U MANAGED About to do