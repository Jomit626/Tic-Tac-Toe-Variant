#ifndef __DATA_STRUCT_H
#define __DATA_STRUCT_H
#include "board.h"
typedef struct nodeLinklist{
    struct nodeTree *tree;
    struct nodeLinklist *next;
} nodeLinklist_t,*linkList_t;

typedef struct decision{
    int ori;
    int dest;
} decision_t;

typedef struct nodeTree{
    double winRate[2];
    board_t board;
    struct decision decision;
    int next_player;
    linkList_t branches;
} nodeTree_t,*tree_t;

tree_t creatTree();
linkList_t creatLinklistNode(tree_t t);
void freeTree(tree_t t);
void addBranche2Tree(tree_t t,tree_t branch);


#endif