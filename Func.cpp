#include "Func"
#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

// Question Functions
bool Func::AskChar(char y, char n, string msg, string error)
{
    string input;
    while (true)
    {
        cout << msg << '\n';
        getline(cin, input);
        cout << '\n';
        if ((input[0] == y || input[0] == y + 32) && input[1] == '\0')
        {
            return true;
        }
        else if ((input[0] == n || input[0] == n + 32) && input[1] == '\0')
        {
            return false;
        }
        else
        {
            cout << error << '\n';
        }
    }
}
int Func::Ask3Char(char option_1, char option_2, char r, string msg, string error)
{
    string input;
    while (true)
    {
        cout << msg << '\n';
        getline(cin, input);
        if(input == "Creator?")
        {
            cout << "Teroro";
        }
        cout << '\n';
        if ((input[0] == option_1 || input[0] == option_1 + 32) && input[1] == '\0')
        {
            return 1;
        }
        else if ((input[0] == option_2 || input[0] == option_2 + 32) && input[1] == '\0')
        {
            return 2;
        }
        else if ((input[0] == r || input[0] == r + 32) && input[1] == '\0')
        {
            return 3;
        }
        else
        {
            cout << error << '\n';
        }
    }
}

// Resetting Maps Funtions
void Func::ClearMap(int m[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m[i][j] = 0;
        }
    }
}
void Func::ResetDrawMap(char m[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m[i][j] = '-';
        }
    }
}

// Input Check for Coordinates
int Func::CheckCord(int Max, string msg, string error)
{
    string input;
    while (true)
    {
        cout << msg << '\n';
        getline(cin, input);
        cout << '\n';
        if (input[0] >= '1' && input[0] <= Max + 48 && input[1] == '\0')
        {
            return input[0] - 49;
        }
        else
        {
            cout << error << '\n';
        }
    }
}

// Check Coordinates
bool Func::CheckMap(int m[3][3], int cord1, int cord2)
{
    if (m[cord1][cord2] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// AI
int Func::Random(int max)
{
    srand(time(NULL));
    return rand() % max;
}

// Win Conditions
bool Func::CheckForEndMap(int m[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Func::CheckWin(int m[3][3], char P, char O)
{
    for (int i = 0; i < 3; i++)
    {
        if (m[i][0] == m[i][1] && m[i][1] == m[i][2] && m[i][0] != 0)
        {
            if (m[i][0] == 1)
            {
                cout << P << " Wins! (slabule)\n";
                return true;
            }
            else
            {
                cout << O << " Wins! (slabule)\n";
                return true;
            }
        }
        else if (m[0][i] == m[1][i] && m[1][i] == m[2][i] && m[0][i] != 0)
        {
            if (m[0][i] == 1)
            {
                cout << P << " Wins! (slabule)\n";
                return true;
            }
            else
            {
                cout << O << " Wins! (slabule)\n";
                return true;
            }
        }
        else if (m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[1][1] != 0)
        {
            if (m[0][0] == 1)
            {
                cout << P << " Wins! (slabule)\n";
                return true;
            }
            else
            {
                cout << O << " Wins! (slabule)\n";
                return true;
            }
        }
        else if (m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[1][1] != 0)
        {
            if (m[0][2] == 1)
            {
                cout << P << " Wins! (slabule)\n";
                return true;
            }
            else
            {
                cout << O << " Wins! (slabule)\n";
                return true;
            }
        }
    }
    return false;
}