#include<stdio.h>
#include<stdbool.h>
void banner();
int findNumDiskOnBoard(int stateOfTheGame[8][8]);
void displayBoard(int stateOfTheGame[8][8], int valMoveLIST[][2], int valMovesCount);
void seekMoveInput(char* pos, int index[2], int currentPlayer);
// bool is_validMove(int stateOfTheGame[8][8], int currentPlayer, int row, int col);
int (*findValidMoves(int stateOfTheGame[8][8], int currentPlayer, int *countValMoves))[2];
void action(int stateOfTheGame[8][8], int row, int col, int currentPlayer);
void playTheGame()
{
    banner();
    int stateOfTheGame[8][8];
    int currentPlayer;
    char move[2], pos[2];
    int index[2];
    int count, count1; // number of valid move current player.
    int numPlayerWithNoValidMove = 0; // number of players with no valid move for a given state
    int numDisks, validMovePlayed;

    bool gameOver = false;
    int turnNum = 0;
    int (*valMoveLIST)[2];

    // initialize the first player
    currentPlayer = 0; // first turn of black player.

    // initialize the state of the board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            stateOfTheGame[i][j] = -1;
        }
    }
    stateOfTheGame[3][3] = stateOfTheGame[4][4] = 1;
    stateOfTheGame[3][4] = stateOfTheGame[4][3] = 0;
    
    // display the initial state
    valMoveLIST= findValidMoves(stateOfTheGame, currentPlayer, &count);    
    displayBoard(stateOfTheGame, valMoveLIST, count);


    // Test case for checking flip-player branch (no valid move left for black)
    // stateOfTheGame[2][3] = stateOfTheGame[3][2] = 0;
    // stateOfTheGame[3][4] = stateOfTheGame[4][3] = 0;
    // stateOfTheGame[4][5] = stateOfTheGame[5][4] = 0;
    // stateOfTheGame[3][3] = stateOfTheGame[4][4] = 1;
    
    // the game begins from here. Play the game until gameOver is true.
    while (gameOver == false)
    {

    turnNum += 1;
    printf(" (Turn number: %d) ", turnNum);
    validMovePlayed = 0; // if a valid move is played, change this to 1
    numDisks = findNumDiskOnBoard(stateOfTheGame);
    if(numDisks == 64)
        {
            printf("GAME OVER!!! No cell left Empty");
            gameOver = true;
            break;
        }
    else
        {
            valMoveLIST= findValidMoves(stateOfTheGame, currentPlayer, &count);    
            if(count == 0)// Branch b2
                {
                    turnNum -= 1;
                    numPlayerWithNoValidMove += 1; // keep an account of number of players with no valid moves
                    if(numPlayerWithNoValidMove == 2) // if both players have no valid move for the same state, GAME is OVER.
                        {
                            printf("GAME OVER!! No valid move left for both player");
                            gameOver = true;
                            break;
                        }
                    else
                        {
                            printf("(Warning!) No valid move exists for %s. \n", currentPlayer==0? "Black":"White");
                            currentPlayer = (currentPlayer==0)? 1 : 0;
                            printf("Changing player. Now current player is %s \n", currentPlayer==0? "Black":"White");
                            valMoveLIST= findValidMoves(stateOfTheGame, currentPlayer, &count);    
                            displayBoard(stateOfTheGame, valMoveLIST, count);

                        }
                }
            else // Branch b1
                {
                    numPlayerWithNoValidMove = 0; // reset the number of players with no valid moves
                    seekMoveInput(pos, index, currentPlayer);

                    for(int i = 0; i <= count; i++)
                    {
                        if(index[0] == valMoveLIST[i][0] && index[1] == valMoveLIST[i][1]) // Branch b1.1
                        {
                            action(stateOfTheGame,index[0],index[1],currentPlayer);
                            currentPlayer = (currentPlayer==0)? 1 : 0;// After successful action: Player changed.
                            valMoveLIST= findValidMoves(stateOfTheGame, currentPlayer, &count);    
                            displayBoard(stateOfTheGame, valMoveLIST, count);
                            gameOver = false;
                            validMovePlayed = 1;
                            break;
                        }
                    }
                         // Branch b1.2
                         if (validMovePlayed == 0)
                         {
                            turnNum -= 1;
                            printf("Invalid move entered. Try again (a valid move exists).\n");
                        }
                }
        }
    }
}

int main()
{
    playTheGame();
    return 0;
}