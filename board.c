#include "board.h"

int getPiece(board_t board,int idx){
    return (board >> (idx<<1))&0b11;
}
/* 
    func putPiece
    assume dest postion is N_PIECE (0b00)
*/
board_t putPiece(board_t board,int dest,int piece){
    return board|(piece<<(dest<<1));
}
/* 
    func movePiece
    assume dest postion is N_PIECE (0b00)
*/
board_t movePiece(board_t board,int ori,int dest){
    // get origin
    int piece = getPiece(board,ori);
    // clear origin
    board_t tmp = (0b11) <<(ori<<1);
    board &=~tmp;
    // put piece to dest
    board |= piece<<(dest<<1);
    return board;
}

int isWin(board_t board){
    /*  horizontal */
    board_t tmp ;
    //if (tmp == 0b010101) return X_PIECE;
    //else if (tmp == 0b101010) return O_PIECE;/* 01 01 01 */
//
    //tmp = (board>>6) & 0x3f; /* Next row */
    //if (tmp == 0b010101) return X_PIECE;
    //else if (tmp == 0b101010) return O_PIECE;
//
    //tmp = (board>>12) & 0x3f; /* Next row */
    //if (tmp == 0b010101) return X_PIECE;
    //else if (tmp == 0b101010) return O_PIECE;
//
//
    ///* vertical */
    //tmp = board&0x30c3;/* 00 00 11:00 00 11:00 00 11 */
    //if(tmp == 0x01041) return X_PIECE;/* 00 00 01:00 00 01:00 00 01 */
    //else if (tmp == 0x02082)  return O_PIECE;/* 00 00 10:00 00 10:00 00 10 */
//
    //tmp = (board>>2)&0x30c3;/* Next col */
    //if(tmp == 0x01041) return X_PIECE;
    //else if (tmp == 0x02082)  return O_PIECE;
//
    //tmp = (board>>4)&0x30c3;/* Next col */
    //if(tmp == 0x01041) return X_PIECE;
    //else if (tmp == 0x02082)  return O_PIECE;

    
    /* diagonal */
    tmp = board&0x30303;/* 11 00 00 00 11 00 00 00 11 */
    if(tmp == 0x10101) return X_PIECE;
    else if(tmp == 0x20202) return O_PIECE;/* 01 00 00 00 01 00 00 00 01 */

    tmp = board&0x03330;/* 00 00 11 00 11 00 11 00 00 */
    if(tmp == 0x01110) return X_PIECE;
    else if(tmp == 0x02220) return O_PIECE;/* 00 00 01 00 01 00 01 00 00 */

    return N_PIECE;
}