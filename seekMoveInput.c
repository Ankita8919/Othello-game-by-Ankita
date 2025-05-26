#include <stdio.h>

void seekMoveInput(char* pos, int index[2], int currentPlayer) 
{
    
    printf("%s to move\n", currentPlayer==0? "Black":"White");
    printf("Enter the move (e.g., b4 for 2nd row and 4th column):");
    scanf("%2s",pos);

    index[0] = pos[0] - 'a';
    index[1] = pos[1] - '1';
}

// int main() {
//     char pos[2] = "--"; // = "b8";
//     int index[2];
//     int currentPlayer = 0;
//     seekMoveInput(pos, index, currentPlayer);
//     printf("[%d, %d]\n", index[0], index[1]);
//     return 0;
// }
