#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_validMove(int stateOfTheGame[8][8], int currentPlayer, int row, int col)
{
    bool found_opponent;
    int r, c, dr, dc;
    if (stateOfTheGame[row][col] != -1)
    {
        return false; // the cell targeted for the move is not empty.
    }
    int opponent = (currentPlayer == 0) ? 1 : 0; // ternary operator is being used here.
    int directions[8][2] = {
                                {-1, -1}, {-1, 0}, {-1, 1},
                                {0, -1}, /*you*/ {0, 1}, 
                                {1, -1}, {1, 0}, {1, 1}};
    // 8 directions and 2 axis.
    for (int i = 0; i < 8; i++)
    {
        dr = directions[i][0];
        dc = directions[i][1];
        r = row + dr;
        c = col + dc;
        bool found_opponent = false;
        while (r >= 0 && r < 8 && c >= 0 && c < 8 && stateOfTheGame[r][c] == opponent)
        {
            r += dr;
            c += dc;
            found_opponent = true;
        }

        if (found_opponent && r >= 0 && r < 8 && c >= 0 && c < 8 && stateOfTheGame[r][c] == currentPlayer)
        {
            return true;
        }

    }
    return false;
}

// {
//     int currentPlayer = 1;

//     int stateOfTheGame[8][8];
//     // initialize stateOfTheGam al empty
//     for (int i = 0; i < 8; i++)
//     {
//         for (int j = 0; j < 8; j++)
//         {
//             stateOfTheGame[i][j] = -1;
//         }
//     }

//     // Test case: 1 (initial state)
//     // stateOfTheGame[3][3] = stateOfTheGame[4][4] = 1;
//     // stateOfTheGame[3][4] = stateOfTheGame[4][3] = 0;
//     // int moveLIST[][2] = {{2, 3}, {5, 4}, {4, 2}};
    
//     // Test case: 2
//     // stateOfTheGame[3][3] = stateOfTheGame[4][4] = 1;
//     // stateOfTheGame[3][4] = stateOfTheGame[4][3] = 0;
//     // stateOfTheGame[4][5] = stateOfTheGame[5][2] = 0;
//     // stateOfTheGame[5][3] = stateOfTheGame[5][4] = 0;

//     // Test case: 3;
//     stateOfTheGame[3][4] = stateOfTheGame[3][5] = 1;
//     stateOfTheGame[5][3] = stateOfTheGame[5][4] = stateOfTheGame[6][4] = 1;
//     stateOfTheGame[2][2] = stateOfTheGame[3][3] = stateOfTheGame[4][4] = 0;
//     stateOfTheGame[5][5] = stateOfTheGame[6][6] = stateOfTheGame[4][3] = 0;
//     stateOfTheGame[4][5] = stateOfTheGame[4][6] = 0;
//     int moveLIST[][2] = {{2,3}, {2,4}, {2,6}, {3,2}, {3,6}, {3,7}, {4,2}, {4,6}, {4,7}, {5,2}, {5,6}, {6,3}, {6,5}, {7,1}, {7,4}, {7,7}};
    
//     //{{3, 2}, {2,3},{4,5},{5,4},{5,5},{3,5},{1,4},{6,3}}; // list of test moves

//     int num_moveLIST = sizeof(moveLIST) / sizeof(moveLIST[0]);

//     printf("current player- %d, \n", currentPlayer);
//     for (int moveId = 0; moveId < num_moveLIST; moveId++)
//     {
//         bool x;
//         x = is_validMove(stateOfTheGame, currentPlayer, moveLIST[moveId][0], moveLIST[moveId][1]);
//         printf("move- (%d, %d) is %d \n", moveLIST[moveId][0], moveLIST[moveId][1], x);
//     }
//     return 0;
// }