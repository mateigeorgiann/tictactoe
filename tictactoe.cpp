#include <iostream>
#include <conio.h>
//The board
char board[4][4];
void simpleAI()
{

}
void clearCIN()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}
//Initialising the board
void createBoard()
{
    for (int i = 1; i <=3; i++)
        for (int j = 1; j <= 3; j++)
            board[i][j] =' ';
}

//Drawing the board 
void draw()
{
   
    std::cout << "     TIC-TAC-TOE     \n\n";
    std::cout << "       |   |\n";
    std::cout << "    "<< board[1][1]<<"  " << "|" <<" "<< board[1][2] << " |  " << board[1][3] << '\n';
    std::cout << "       |   |"<<'\n';
    std::cout << " ------+---+------"<<'\n';
    std::cout << "       |   |\n";
    std::cout << "    " << board[2][1] << "  " << "|" << " " << board[2][2] << " |  " << board[2][3] << '\n';
    std::cout << "       |   |" << '\n';
    std::cout << " ------+---+------" << '\n';
    std::cout << "       |   |\n";
    std::cout << "    " << board[3][1] << "  " << "|" << " " << board[3][2] << " |  " << board[3][3] << '\n';
    std::cout << "       |   |" << '\n';
}

//Takes the turn of the respecting player
void takeTurn(char currentPlayer)
{
    if (currentPlayer == 'X')
        std::cout << "X is playing now :";
    else
        std::cout << "O is playing now :";
        while (true) {
            static int i = { -1 }, j = { -1 };
            std::cin >> i >> j;
            if (i > 0 && i < 4 && j>0 && j < 4 && board[i][j]==' ') {
                board[i][j] = currentPlayer;
                break;
            }
            std::cout << "\nIllegal move\n";
            clearCIN();
        }
}

//Check all directions if its winnable
bool checkWinning(char currentPlayer, bool turn,int& playerScore1, int& playerScore2,char player1, char player2)
{
    if (
        ((board[1][1] == board[1][2] && board[1][2] == board[1][3]) && (board[1][1] != ' '))
        || ((board[2][1] == board[2][2] && board[2][2] == board[2][3]) && (board[2][1] != ' '))
        || ((board[3][1] == board[3][2] && board[3][2] == board[3][3]) && (board[3][1] != ' '))
        || ((board[1][1] == board[2][1] && board[2][1] == board[3][1]) && (board[1][1] != ' '))
        || ((board[1][2] == board[2][2] && board[2][2] == board[3][2]) && (board[1][2] != ' '))
        || ((board[1][3] == board[2][3] && board[2][3] == board[3][3]) && (board[1][3] != ' '))
        || ((board[1][1] == board[2][2] && board[2][2] == board[3][3]) && (board[1][1] != ' '))
        || ((board[1][3] == board[2][2] && board[2][2] == board[3][1]) && (board[1][3] != ' '))
        ) {
        draw();
        std::cout << currentPlayer << " has won !\n\n";
        if (((turn==0) && (currentPlayer == 'O')) || ((turn) && (currentPlayer == 'X')))
             playerScore1++;
        else
            playerScore2++;
        std::cout << player1 << "'s score= " << playerScore1 << "\n\n" << player2 << "'s score = " << playerScore2;
        return true;
    }
    return false;
}

//Playing the Game :3
void playGame(char& player1, char& player2, bool& turn,int& playerScore1,int& playerScore2)
{
    static int turnNumber = { 1 };
    static char currentPlayer;
    if (turn) {
        std::cout << player1 << " plays as X\n" << player2 << " plays as O\n";
    }
    else
    {
        std::cout << player2 << " plays as X\n" << player1 << " plays as O\n";   
    }
        currentPlayer = 'X';
        turnNumber = 1;
    //the 1st player takes their turn , then the turn number icnreases, changes the currentPlayer
    while (turnNumber<=9)
    {
        draw();
        //lets currentPlayer choose a space where they can play
        takeTurn(currentPlayer);
        turnNumber++;
        system("cls");
        //you cant win in less than 5 turns so we eliminate half of the comparation
        if (turnNumber > 5)
            if (checkWinning(currentPlayer, turn, playerScore1, playerScore2, player1, player2))
            {
                draw();
                std::cout << currentPlayer << " has won !\n\n";
                if (((turn == 0) && (currentPlayer == 'O')) || ((turn) && (currentPlayer == 'X')))
                    playerScore1++;
                else
                    playerScore2++;
                std::cout << player1 << "'s score= " << playerScore1 << "\n\n" << player2 << "'s score = " << playerScore2;
                break;
            }
        if (turnNumber == 10)
            std::cout << "\nDRAW";

        //changes player turn
         if (currentPlayer == 'O')
        {
            currentPlayer = 'X';
        }
        else
            currentPlayer = 'O';
    }
        

    
    //clean terminal;
    
}

//Set the names of the players
void setNames(int& playerScore1, int& playerScore2,char&player1, char& player2)
{
    playerScore1 = { 0 };
    playerScore2 = { 0 };
    std::cout << "Enter player 1 name: ";
    std::cin >> player1;
    clearCIN();
    std::cout << "\nEnter player 2 name: ";
    std::cin >> player2;
    clearCIN();
}


int main()
{
    //if its turn 0, player 1 moves first, if its turn 1 player 2 moves first , it alternates
    restartAgain:
    bool turn = 0;
    int playerScore1;
    int playerScore2;
    char player1sign;
    char player2sign;
    std::string player1name;
    std::string player2name;
    char mode;

    while (true)
    {
        std::cout << "Do you want to play single player or multiplayer ? Press S or M :";
            mode = _getch();
        if (mode == 'S' || mode == 'M')
            break;
    }
    //add multiplayer ,a dumb ai that chooses random places if not specified


    setNames(playerScore1, playerScore2, player1, player2);
    char wantPlay = {};
    while (true)
    {
        playAgain:
        createBoard();
        system("cls");
        playGame(player1, player2, turn, playerScore1, playerScore2);
        turn = !turn;
        //do you want to continue , or restart;
        askAgain:
            std::cout << "\n\nDo you still want to play ? type Y to continue, R to restart the score, N to stop playing";
            wantPlay = _getch();

            switch (wantPlay)
            {
            case 'Y':
            {
                system("cls");
                goto playAgain;
                break;
            }
            case 'R':
            {
                system("cls");
                goto restartAgain;
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
            std::cin.clear();
            std::cin.ignore(1000, '\n');

    }
    noMore:
    system("cls");
    std::cout << "\n Thank you for playing !\n \NThe final score is " << playerScore1 << " for " << player1 << " and " << playerScore2 << " for " << player2;
    return 0;
}