#include <stdio.h>
#include "board.h"

int main(int argc, char const *argv[])
{
    board_t b = 0;
    int dest;
    while (1)
    {
        scanf("%d", &dest);
        b = putPiece(b, dest, O_PIECE);
        printf("::%d\n", isWin(b));
    }
    return 0;
}
