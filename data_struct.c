#include "data_struct.h"
#include <stdlib.h>

tree_t creatTree(){
    tree_t t = (tree_t) malloc(sizeof(nodeTree_t));
    t->branches = creatLinklistNode(NULL);
    t->winRate[0] = .0;
    t->winRate[1] = .0;
    t->board = 0;
    return t;
}

linkList_t creatLinklistNode(tree_t t){
    linkList_t L = (linkList_t)malloc(sizeof(nodeLinklist_t));
    L->tree = t;
    L->next = NULL;
    return L;
}

void freeTree(tree_t t){
    if(t){
        linkList_t branches = t->branches;
        while(branches->next){
            linkList_t tmp = branches;
            branches = branches->next;
            freeTree(tmp->tree);
            free(tmp);
        }
        free(t);
    }
}

void addBranche2Tree(tree_t t,tree_t branch){
    linkList_t L = creatLinklistNode(branch);
    linkList_t branches = t->branches;

    L->next = branches->next;
    branches->next = L;
}

void caculateWinRate(tree_t t){
    linkList_t b = t->branches;
    if(!b->next) return;

    unsigned int nodeCount = 0;
    double XWinRate=.0,OWinRate=.0;
    while(b->next){
        nodeCount++;
        caculateWinRate(b->next->tree);
        XWinRate+=b->next->tree->winRate[X_PIECE-1];
        OWinRate+=b->next->tree->winRate[O_PIECE-1];
        b = b->next;
    }
    t->winRate[X_PIECE-1] = XWinRate/nodeCount;
    t->winRate[O_PIECE-1] = OWinRate/nodeCount;
}