#include "data_struct.h"
#include <stdlib.h>

tree_t creatTree(){
    tree_t t = (tree_t) malloc(sizeof(nodeTree_t));
    t->branches = creatLinklistNode(NULL);
    t->X_winRate = .0;
    t->O_winRate = .0;
}

linkList_t creatLinklistNode(tree_t t){
    linkList_t L = (linkList_t)malloc(sizeof(nodeLinklist_t));
    L->tree = t;
    L->next = NULL;
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
        XWinRate+=b->next->tree->X_winRate;
        OWinRate+=b->next->tree->O_winRate;
        b = b->next;
    }
    t->O_winRate = OWinRate/nodeCount;
    t->X_winRate = XWinRate/nodeCount;
}