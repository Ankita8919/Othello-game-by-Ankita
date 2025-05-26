#include<stdio.h>
#include <stdbool.h>
#include <string.h>
#include<stdlib.h>

int (*findValidMoves(int stateOfTheGame[8][8], int currentPlayer, int *countValMoves))[2];
void displayBoard(int stateOfTheGame[8][8], int valMoveLIST[][2], int ValMovesCount)
{
    
    int scoreB = 0;
    int scoreW = 0;
 
    printf("\t");
    for(int i = 0; i < 8; i++)
    {
        printf("%d\t",i+1);
    }
    char ch = 'a';
    for(int u = 0; u < 8; u++)
        {
            printf("\n");
            printf("%c\t",ch);
            for(int v = 0; v < 8; v++ )
            {
                if(stateOfTheGame[u][v]==1)
                {
                    scoreW += 1;
                    printf("w\t");
                }
                else if(stateOfTheGame[u][v]==0)
                {
                    scoreB += 1;
                    printf("b\t");
                }
                else 
                {
                    int printDotForEmptyCell = 1;
                    for(int kk = 0; kk < ValMovesCount ; kk++)
                    {
                        if(u == valMoveLIST[kk][0] && v == valMoveLIST[kk][1])
                        {
                            printf("_\t");
                            printDotForEmptyCell=0;
                            break;
                        }
                    }
                    if (printDotForEmptyCell==1)
                    {
                        printf(".\t");
                    }
                }
            }
            printf("%c\t",ch);
            ch=ch+1;
        }
            printf("\n\t");
            for(int j = 0; j < 8; j++)
            {
                printf("%d\t",j+1);
            }
        printf("\n");
    
        printf("  =======================================================\n");
        printf("     \t   Black : %d \t\t White : %d   \t\t  \n", scoreB, scoreW);
        printf("  =======================================================\n");
}

// int main()
// {
//     int i,j;
//     int stateOfTheGame[8][8];
//     for (i = 0; i < 8; i++)
//     {
//         for (j = 0; j < 8; j++)
//         {
//             stateOfTheGame[i][j] = -1;
//         }
//     }
//     //  Test case 1 : initial state
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
//     // stateOfTheGame[2][2] = stateOfTheGame[3][3] = stateOfTheGame[4][3] = 0;
//     // stateOfTheGame[4][4] = stateOfTheGame[4][5] = stateOfTheGame[4][6] = 0;
//     // stateOfTheGame[5][5] = stateOfTheGame[6][6] = 0;

//     // Test case: 4 (no valid move left for black)
//     // stateOfTheGame[2][3] = stateOfTheGame[3][2] = 0;
//     // stateOfTheGame[3][4] = stateOfTheGame[4][3] = 0;
//     // stateOfTheGame[4][5] = stateOfTheGame[5][4] = 0;
//     // stateOfTheGame[3][3] = stateOfTheGame[4][4] = 1;


//     // if current player is black.
//     // int validMoves[64][2] = {{3,2}};
//     int currentPlayer = 0;
//     int count;
//     int (*valMoveLIST )[2] = findValidMoves(stateOfTheGame, currentPlayer, &count);

//     displayBoard(stateOfTheGame, valMoveLIST);
       
//     return 0;
// }