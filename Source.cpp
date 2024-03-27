#include <iostream>
#include <conio.h>
#include <utility>
#include <algorithm>
#include "functions.h"
#include "global_variables.h"

//MULTIPLAYER AND SINGLEPLAYER ARE REVERSED, I PROGRAMMED THE WHOLE THING LIKE THIS I JUST REALISED IT AFTER TESTING IT ON MY FRIEND ADN ASKED ME WHY THEY ARE SWITCHED
int main()
{
    
    

    char mode;
    mode = modeOfPlay();
    static char wantPlay = {};
    //ASKS PLAYER IF THEY WANT SINGLE PLAYER OR MULTIPLAER

    //THIS IS FOR SINGLE PLAYER
    if (mode == 'M')
    {
        setNames();
        playAgainS:
        
        //not entering the function
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




