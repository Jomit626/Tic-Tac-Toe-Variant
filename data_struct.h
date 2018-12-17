#ifndef __DATA_STRUCT_H
#define __DATA_STRUCT_H
typedef struct nodeLinklist{
    struct nodeTree *tree;
    struct nodeLinklist *next;
} nodeLinklist_t,*linkList_t;

typedef struct nodeTree{
    double X_winRate;
    double O_winRate;
    linkList_t branches;
} nodeTree_t,*tree_t;

tree_t creatTree();
linkList_t creatLinklistNode(tree_t t);
void freeTree(tree_t t);
void addBranche2Tree(tree_t t,tree_t branch);

void caculateWinRate(tree_t t);

#endif