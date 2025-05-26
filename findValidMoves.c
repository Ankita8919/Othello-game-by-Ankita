#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<stdlib.h>
 
bool is_validMove(int stateOfTheGame[8][8], int currentPlayer, int row, int col);

int (*findValidMoves(int stateOfTheGame[8][8], int currentPlayer, int *countValMoves))[2]
{
    int (*validMoveLIST)[2] = NULL;
    int count = 0;
    bool x;
    
    for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {                
                x = is_validMove(stateOfTheGame,currentPlayer,row,col);

                if (x==1)
                {         
                    int (*tmp)[2] = realloc(validMoveLIST, (count + 1) * sizeof *validMoveLIST);
                    validMoveLIST = tmp;
                    validMoveLIST[count][0] = row;
                    validMoveLIST[count][1] = col;
                    count += 1;
                }
            }
        }
    
    *countValMoves = count; 
    return validMoveLIST;
}

// int main()
// {
//     int count;
//     int currentPlayer = 1;
//     int stateOfTheGame[8][8];
    
//     // initialize stateOfTheGam all empty
//     for (int i = 0; i < 8; i++)
//     {
//         for (int j = 0; j < 8; j++)
//         {
//             stateOfTheGame[i][j] = -1;
//         }
//     }

//     // Test case: 1 (initial state)
//     stateOfTheGame[3][3] = stateOfTheGame[4][4] = 1;
//     stateOfTheGame[3][4] = stateOfTheGame[4][3] = 0;
    
//     // Test case: 2
//     // stateOfTheGame[3][3] = stateOfTheGame[4][4] = 1;
//     // stateOfTheGame[3][4] = stateOfTheGame[4][3] = 0;
//     // stateOfTheGame[4][5] = stateOfTheGame[5][2] = 0;
//     // stateOfTheGame[5][3] = stateOfTheGame[5][4] = 0;

//     // Test case: 3;
//     // stateOfTheGame[3][4] = stateOfTheGame[3][5] = 1;
//     // stateOfTheGame[5][3] = stateOfTheGame[5][4] = stateOfTheGame[6][4] = 1;
//     // stateOfTheGame[2][2] = stateOfTheGame[3][3] = stateOfTheGame[4][4] = 0;
//     // stateOfTheGame[5][5] = stateOfTheGame[6][6] = stateOfTheGame[4][3] = 0;
//     // stateOfTheGame[4][5] = stateOfTheGame[4][6] = 0;
//     int (*valMoveLIST)[2] = findValidMoves(stateOfTheGame, currentPlayer, &count);
//     printf("current player- %d, \t count of valid moves- %d \n", currentPlayer, count);
//     // printf("(%d, %d) \n", valMoveLIST[0][0], valMoveLIST[0][1]);
//     // printf("(%d, %d) \n", valMoveLIST[1][0], valMoveLIST[1][1]);
//     // printf("(%d, %d) \n", valMoveLIST[2][0], valMoveLIST[2][1]);
//     // printf("(%d, %d) \n", valMoveLIST[3][0], valMoveLIST[3][1]);

//     printf("size of valMoveLIST is %d \n", sizeof(valMoveLIST));
//     return 0;
// }