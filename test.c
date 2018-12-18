#include <stdio.h>
#include "board.h"
#include "data_struct.h"
#include "AI.h"
tree_t constructTree(){
    tree_t t = creatTree();
    tree_t A = creatTree();
    tree_t B = creatTree();
    tree_t C = creatTree();
    tree_t D = creatTree();
    tree_t E = creatTree();
    tree_t F = creatTree();
    tree_t G = creatTree();
    addBranche2Tree(t,B);
    addBranche2Tree(t,C);
    addBranche2Tree(t,A);
    addBranche2Tree(A,D);
    addBranche2Tree(A,E);
    addBranche2Tree(E,F);
    addBranche2Tree(E,G);
    B->winRate[1] = 0;
    C->winRate[1] = 0;
    D->winRate[1] = 1;
    F->winRate[1] = 0;
    G->winRate[1] = 1;
    B->winRate[0] = 0;
    C->winRate[0] = 0;
    D->winRate[0] = 0;
    F->winRate[0] = 0;
    G->winRate[0] = 1;

    return t;
}

board_t constructBoard(){
    /* 
        X 1 2
        O X O
        X O 8
    */
    board_t b = 0;
    b = putPiece(b,0,X_PIECE);
    b = putPiece(b,4,X_PIECE);
    b = putPiece(b,6,X_PIECE);

    b = putPiece(b,3,O_PIECE);
    b = putPiece(b,5,O_PIECE);
    b = putPiece(b,7,O_PIECE);
    return b;
}
void printBoard(board_t b){
    char c[3] = {' ','X','O'};
    int t = b&0b11;
    printf("%c ",c[t]);
    t = (b>>=2)&0b11;
    printf("%c ",c[t]);
    t = (b>>=2)&0b11;
    printf("%c ",c[t]);
    putchar('\n');

    t = (b>>=2)&0b11;
    printf("%c ",c[t]);
    t = (b>>=2)&0b11;
    printf("%c ",c[t]);
    t = (b>>=2)&0b11;
    printf("%c ",c[t]);
    putchar('\n');

    t = (b>>=2)&0b11;
    printf("%c ",c[t]);
    t = (b>>=2)&0b11;
    printf("%c ",c[t]);
    t = (b>>=2)&0b11;
    printf("%c ",c[t]);
    putchar('\n');
}
int main(int argc, char const *argv[])
{
    board_t b = constructBoard();
    decision_t d;
    printBoard(b);
    while(!isWin(b)){
        initAI(b,X_PIECE,O_PIECE,13);
        d = makeDecisionAI();
        b = movePiece(b,d.ori,d.dest);
        printf("AI X decide to move %d to %d\n",d.ori,d.dest);
        printBoard(b);

        if(isWin(b)) break;
        getchar();
        initAI(b,O_PIECE,X_PIECE,12);
        d = makeDecisionAI();
        b = movePiece(b,d.ori,d.dest);
        printf("AI O decide to move %d to %d\n",d.ori,d.dest);
        printBoard(b);
        getchar();
    }
/*     tree_t t = constructTree();
    caculateWinRate(t);
    printf("%lf %lf",t->winRate[0],t->winRate[1]); */
    return 0;
}
