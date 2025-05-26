#include<stdio.h>
#include<stdbool.h>
int findNumDiskOnBoard(int stateOfTheGame[8][8])
{  
    int numDisk = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(stateOfTheGame[i][j] == 0 || stateOfTheGame[i][j] == 1)
            {
                numDisk += 1;
            }
        }
    }
    return numDisk;
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
//     printf("Number of disks on board is %d \n", findNumDiskOnBoard(stateOfTheGame));
//     return 0;
// }