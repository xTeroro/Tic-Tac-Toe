#include "Liby"
#include <climits>
#include <iostream>

using namespace std;
using namespace Func;

int scores[3] = {1, -1, 0};

int Bot::MiniMax(int map[3][3], int depth, bool isMaximizing, char P, char O, char dmap[3][3])
{
    if (CheckWin(map, P, O) == 'P')
    {
        return scores[0];
    }
    else if (CheckWin(map, P, O) == 'O')
    {
        return scores[1];
    }
    if (isMaximizing == true)
    {
        int bestScore = INT_MIN;
        int iMove, jMove;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (map[i][j] == 0)
                {
                    map[i][j] = 2;
                    int score = MiniMax(map, depth + 1, false, P, O, dmap);
                    map[i][j] = 0;
                    if (score > bestScore)
                    {
                        bestScore = score;
                        iMove = i;
                        jMove = j;
                    }
                }
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = INT_MAX;
        int iMove, jMove;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (map[i][j] == 0)
                {
                    map[i][j] = 1;
                    int score = MiniMax(map, depth + 1, true, P, O, dmap);
                    map[i][j] = 0;
                    if (score < bestScore)
                    {
                        bestScore = score;
                        iMove = i;
                        jMove = j;
                    }
                }
            }
        }
        return bestScore;
    }
}

void Bot::BotTurn(int map[3][3], char P, char O, char dmap[3][3])
{
    int bestScore = INT_MIN;
    int iMove, jMove;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 2;
                int score = MiniMax(map, 0, false, P, O, dmap);
                map[i][j] = 0;
                if (score > bestScore)
                {
                    bestScore = score;
                    iMove = i;
                    jMove = j;
                }
            }
        }
    }

    map[iMove][jMove] = 2;
    dmap[iMove][jMove] = O;
}