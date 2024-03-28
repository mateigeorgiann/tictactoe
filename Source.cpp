#include <iostream>
#include <conio.h>
#include <utility>
#include <algorithm>
#include "functions.h"
#include "global_variables.h"
//I REALLY TRIED ELIMINATING HEADER FILES BUT I KEPT GETTING LNK2005 , ive read the whole pae on lear.microsoft and I was onlt able to fix the variables
//not the functions, so to not program everything from 0 because i really cant figure out what to do , ill keep it like this for tic tac toe
//as its not a big final project.if you could help me with the error i would be glad to learn how to solve it
// i tried making a functions.cpp replaced stuff around , and it kept sayng that it is already defined in functions.obj 



    
//MULTIPLAYER AND SINGLEPLAYER ARE REVERSED, I PROGRAMMED THE WHOLE THING LIKE THIS I JUST REALISED IT AFTER TESTING IT ON MY FRIEND ADN ASKED ME WHY THEY ARE SWITCHED
int main()
{
    
    
    //ask the dimensions of the game
    askSizes();

    //used for choosing single player or multi
    char mode;
    mode = modeOfPlay();
    static char wantPlay = {};

   
    // That means add a generalised way of draw()
    // Check winnings function diffrently 
    // 
    //ASKS PLAYER IF THEY WANT SINGLE PLAYER OR MULTIPLAER
    
    //THIS IS FOR SINGLE PLAYER
    if (mode == 'M')
    {
        setNames();
        playAgainS:
        
        
        playSinglePlayer();
        draw();
        turn = !turn;
        askAgainS:
        std::cout << "\n\nDo you still want to play ? type Y to continue, N to stop playing";
    wantPlay = _getch();
        switch (wantPlay)
        {
        case 'Y':
        {
            system("cls");
            goto playAgainS;
            break;
        }
        case 'N':
        {
            system("cls");
            goto noMore;
            break;
        }
        default:
        {
            goto askAgainS;
            break;
        }
        }
        clearCIN();

    }
        
    //THIS IS FOR MULTIPLAYER
    else if (mode == 'S')
    {
        std::cout << "Choose your name:";
        std::cin >> player1name;
        player2name = "AI";

    playAgain:

        playMultiPlayer();
        draw();
        turn = !turn;
    askAgain:
        std::cout << "\n\nDo you still want to play ? type Y to continue, N to stop playing";
        wantPlay = _getch();
        switch (wantPlay)
        {
        case 'Y':
        {
            system("cls");
            goto playAgain;
            break;
        }
        case 'N':
        {
            system("cls");
            goto noMore;
            break;
        }
        default:
        {
            goto askAgain;
            break;
        }
        }
        clearCIN();
    }

    noMore:
    endGame();
}




