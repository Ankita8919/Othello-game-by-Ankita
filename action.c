#include<stdio.h>
#include <stdbool.h>

//void displayBoard(int stateOfTheGame[8][8]);

int action(int stateOfTheGame[8][8], int row, int col, int currentPlayer)
{
    int opponent = (currentPlayer == 0) ? 1 : 0;
    stateOfTheGame[row][col] = currentPlayer;
    int directions[8][2] = {
                                {-1,  0}, {-1,  1}, { 0,  1},
                                { 1,  1},/*YOU*/{ 1,  0}, 
                                { 1, -1}, { 0, -1}, {-1, -1} }; // Check all 8 directions
    for (int i = 0; i < 8; i++) 
    {
        int dr = directions[i][0]; // dr is delta row which means change in row.
        int dc = directions[i][1]; // dc is delta column which means change in column.
        int r = row + dr;
        int c = col + dc;
        bool found_opponent = false; 
        int check = stateOfTheGame[r][c];

        while (r >= 0 && r < 8 && c >= 0 && c < 8 && stateOfTheGame[r][c] == opponent)
        {
            r += dr;
            c += dc;
            found_opponent = true;
        }

        // If valid flip line: opponent discs followed by player's own
        if (found_opponent && r >= 0 && r < 8 && c >= 0 && c < 8 && stateOfTheGame[r][c] == currentPlayer) 
        {
            int flip_r = row + dr;
            int flip_c = col + dc;


             while (flip_r != r || flip_c != c)
             {
                stateOfTheGame[flip_r][flip_c] = currentPlayer;
                flip_r += dr;
                flip_c += dc;
            }
        }
    }
}

// int main()
// {
//     // printf("HEllo\n");
//     int stateOfTheGame[8][8];
//     //int newstateOfTheGame[8][8] = NULL;
//     int currentPlayer = 0;

//     // define the state of the game for testing is_valid function
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

//     // Test case: 2
//     stateOfTheGame[2][5] = stateOfTheGame[3][2] = 0;
//     stateOfTheGame[3][3] = stateOfTheGame[3][4] = 0;
//     stateOfTheGame[2][4] = stateOfTheGame[4][2] = 1;
//     stateOfTheGame[4][3] = stateOfTheGame[4][4] = 1;

//     // Test case: 3;
//     // stateOfTheGame[3][4] = stateOfTheGame[3][5] = 1;
//     // stateOfTheGame[5][3] = stateOfTheGame[5][4] = stateOfTheGame[6][4] = 1;
//     // stateOfTheGame[2][2] = stateOfTheGame[3][3] = stateOfTheGame[4][4] = 0;
//     // stateOfTheGame[5][5] = stateOfTheGame[6][6] = stateOfTheGame[4][3] = 0;
//     // stateOfTheGame[4][5] = stateOfTheGame[4][6] = 0;
//     printf("Initial state of the Game.\n");
//     displayBoard(stateOfTheGame);
    
//     action(stateOfTheGame,5,2, currentPlayer);
//     int row = 5;
//     int col = 2;
//     printf("Move by the current player is (%d,%d) {row and col both starts from 0} \n",row, col);
    
//     printf("New state of the game. \n");
//     displayBoard(stateOfTheGame);
//     return 0;
//}