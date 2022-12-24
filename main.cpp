#include <iostream>
#include "Liby"
#include "windows.h"
#include "unistd.h"

using namespace std;
using namespace Func;
using namespace Bot;

// Core Variables
char Player, Opponent;
char DrawMap[3][3];
int Map[3][3];
void SetUp()
{
    int id;
    id = Ask3Char('x', '0', 'r', "Select your character X or 0 or R(random) : ", "Invalid character, please try again.");
    if (id == 1)
    {
        Player = 'X';
        Opponent = '0';
    }
    else if (id == 2)
    {
        Player = '0';
        Opponent = 'X';
    }
    else
    {
        id = Random(2) + 1;
        if (id == 1)
        {
            Player = 'X';
            Opponent = '0';
        }
        else
        {
            Player = '0';
            Opponent = 'X';
        }
        cout << "Player character is: " << Player << '\n'
             << "Opponent character is: " << Opponent << "\n\n";
    }
    ClearMap(Map);
    ResetDrawMap(DrawMap);
}

// Game Variables
int ColumnCord, RowCord, OpponentCord, Round;
int BotCards[10], CardsCount;
void Draw()
{
    cout << "  " << 1 << " " << 2 << " " << 3 << '\n';
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ' ';
        for (int j = 0; j < 3; j++)
        {
            cout << DrawMap[i][j] << ' ';
        }
        cout << '\n';
    }
}

void SinglePlayerGame()
{
    SetUp();
    Round = 0;
    while (true)
    {
        if (Round == 0 && Player == '0')
        {
            // Opponent Turn when Player is 0
            Round++;
            cout << "The Opponent Choosed: " << ColumnCord + 1 << " and " << RowCord + 1 << '\n';
        }
        Draw();
        cout << '\n';
        // Player Turn
        while (true)
        {
            ColumnCord = CheckCord(3, "Enter the row coordinate (from up to down): ", "Invalid coordinate, please try again.");
            RowCord = CheckCord(3, "Enter the column coordinate (from left to right): ", "Invalid coordinate, please try again.");
            if (CheckMap(Map, ColumnCord, RowCord) == true)
            {
                Map[ColumnCord][RowCord] = 1;
                DrawMap[ColumnCord][RowCord] = Player;
                break;
            }
            else
            {
                cout << "T~his (but a scratch) coordinate is already taken, please try again \n"<< '\n';
            }
        }
        // Check for Player Win
        if (CheckWin(Map, Player, Opponent) == Player)
        {
            cout<<"Player Wins! (Slabule)";
            Draw();
            break;
        }else if(CheckForEndMap(Map) == true)
        {
            cout << "Draw!" << '\n';
            Draw();
            cout << '\n';
            break;
        }
        // AI Turn
        BotTurn(Map, Player, Opponent, DrawMap);
        /*
        for (int i = 0; i <= 9; i++)
        {
            BotCards[i] = i;
        }
        CardsCount = 9;
        while (true)
        {
            OpponentCord = Random(CardsCount);
            if (OpponentCord < 3)
            {
                ColumnCord = 0;
                RowCord = OpponentCord;
            }
            else if (OpponentCord < 6)
            {
                ColumnCord = 1;
                RowCord = OpponentCord - 3;
            }
            else
            {
                ColumnCord = 2;
                RowCord = OpponentCord - 6;
            }
            if (CheckMap(Map, ColumnCord, RowCord) == true)
            {
                Map[ColumnCord][RowCord] = 2;
                DrawMap[ColumnCord][RowCord] = Opponent;
                break;
            }
            else
            {
                BotCards[OpponentCord] = BotCards[CardsCount];
                CardsCount--;
            }
        }
        */
        //cout << "The Opponent Choosed: " << ColumnCord + 1 << " and " << RowCord + 1 << '\n';
        // Check for Opponent Win
        if (CheckWin(Map,Player,Opponent) == Opponent)
        {
            cout<<"Opponent Wins! (Slabule)";
            Draw();
            break;
        }
        else if (CheckForEndMap(Map) == true)
        {
            cout << "Draw!" << '\n';
            Draw();
            cout << '\n';
            break;
        }
    }
    if (AskChar('y', 'n', "Do you want to play again? (y/n)", "Invalid character, please try again.") == true)
    {
        SinglePlayerGame();
    }
}
void MultiPlayerGame()
{
    SetUp();
    Round = 0;
    while (true)
    {
        if (Round == 0 && Player == '0')
        {
            //Opponent Play if Player is 0
            cout << "Opponents Turn" << '\n';
            while (true)
            {
                ColumnCord = CheckCord(3, "Enter the row coordinate (from up to down): ", "Invalid coordinate, please try again.");
                RowCord = CheckCord(3, "Enter the column coordinate (from left to right): ", "Invalid coordinate, please try again.");
                if (CheckMap(Map, ColumnCord, RowCord) == true)
                {
                    Map[ColumnCord][RowCord] = 2;
                    DrawMap[ColumnCord][RowCord] = Opponent;
                    break;
                }
                else
                {
                    cout << "T~his (but a scratch) coordinate is already taken, please try again \n"
                         << '\n';
                }
            }
            Round++;
        }
        // Player Turn
        Draw();
        cout << '\n';
        cout << "Player Turn" << '\n';
        while (true)
        {
            ColumnCord = CheckCord(3, "Enter the row coordinate (from up to down): ", "Invalid coordinate, please try again.");
            RowCord = CheckCord(3, "Enter the column coordinate (from left to right): ", "Invalid coordinate, please try again.");
            if (CheckMap(Map, ColumnCord, RowCord) == true)
            {
                Map[ColumnCord][RowCord] = 1;
                DrawMap[ColumnCord][RowCord] = Player;
                break;
            }
            else
            {
                cout << "T~his (but a scratch) coordinate is already taken, please try again \n"
                     << '\n';
            }
        }

        // Check for Player Win
        if (CheckWin(Map, Player, Opponent) == true)
        {
            Draw();
            cout << '\n';
            break;
        }
        else if (CheckForEndMap(Map) == true)
        {
            cout << "Draw!" << '\n';
            Draw();
            cout << '\n';
            break;
        }
        // Player2 Turn
        Draw();
        cout << '\n';
        cout << "Opponents Turn" << '\n';
        while (true)
        {
            ColumnCord = CheckCord(3, "Enter the row coordinate (from up to down): ", "Invalid coordinate, please try again.");
            RowCord = CheckCord(3, "Enter the column coordinate (from left to right): ", "Invalid coordinate, please try again.");
            if (CheckMap(Map, ColumnCord, RowCord) == true)
            {
                Map[ColumnCord][RowCord] = 2;
                DrawMap[ColumnCord][RowCord] = Opponent;
                break;
            }
            else
            {
                cout << "T~his (but a scratch) coordinate is already taken, please try again \n"
                     << '\n';
            }
        }
        // Check for Opponent Win
        if (CheckWin(Map, Player, Opponent) == true)
        {
            cout << '\n';
            Draw();
            cout << '\n';
            break;
        }
        else if (CheckForEndMap(Map) == true)
        {
            cout << "Draw!" << '\n';
            Draw();
            cout << '\n';
            break;
        }
    }
    if (AskChar('y', 'n', "Do you want to play again? (y/n)", "Invalid character, please try again.") == true)
    {
        MultiPlayerGame();
    }
}

int main()
{
    cout << "=======\n|| B ||\n|| Y ||\n||   ||\n|| T ||\n|| E ||\n|| R ||\n|| O ||\n|| R ||\n|| O ||\n======= \n\n\n\n";
    cout << "Welcome to Tic Tac Toe!\n\n";
    if (AskChar('C', 'F', "Do you want to play against the computer or a friend? (C/F)", "Please enter a valid input."))
    {
        cout << "You chose to play against the computer.\n\n";
        SinglePlayerGame();
    }
    else
    {
        cout << "You chose to play against a friend.\n\n";
        MultiPlayerGame();
    }

    // Exit Sequence
    cout << "The Program will automatically exit when the timer reaches 0." << '\n';
    for (int i = 5; i > 0; i--)
    {
        cout << i << '\n';
        sleep(1);
    }
}