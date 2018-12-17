#ifndef __BOARD_H
#define __BOARD_H
#include <stdint.h>
/* 
    Board position label
    0 1 2
    3 4 5
    6 7 8 
    Each position occupies 2 bits in a 32 bits int
*/

#define X_PIECE (0b01)
#define O_PIECE (0b10)
#define N_PIECE (0b00)

typedef uint32_t board_t;

int getPiece(board_t board, int idx);
board_t movePiece(board_t board, int ori, int dest);
board_t putPiece(board_t board, int dest, int piece);
//return winning piece
int isWin(board_t board);
#endif
