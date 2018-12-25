#include "data_struct.h"
#include <stdlib.h>
#include "imalloc.h"

tree_t creatTree(){
    tree_t t = (tree_t) imalloc(sizeof(nodeTree_t));
    t->branches = creatLinklistNode(NULL);
    t->winRate[0] = .0;
    t->winRate[1] = .0;
    t->board = 0;
    return t;
}

linkList_t creatLinklistNode(tree_t t){
    linkList_t L = (linkList_t)imalloc(sizeof(nodeLinklist_t));
    L->tree = t;
    L->next = NULL;
    return L;
}

void freeTree(tree_t t){
    reInit();
}

void addBranche2Tree(tree_t t,tree_t branch){
    linkList_t L = creatLinklistNode(branch);
    linkList_t branches = t->branches;

    L->next = branches->next;
    branches->next = L;
}

