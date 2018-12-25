#include "board.h"
#include "data_struct.h"
#include "imalloc.h"
#include "AI.h"

tree_t searchTree;
int role,compititor,searchLevel;

void constructFullTree(tree_t t,int level);

void creatDecisionTreeNode(tree_t parent,int level,int ori,int dest){
    if(getPiece(parent->board,dest)) return;
    tree_t tmp = creatTree();
    tmp->board = movePiece(parent->board,ori,dest);
    tmp->decision.dest = dest;
    tmp->decision.ori = ori;

    tmp->next_player = parent->next_player == X_PIECE ? O_PIECE : X_PIECE;
    switch(isWin(tmp->board)){
        case N_PIECE:
            constructFullTree(tmp,level-1);
            break;
        case X_PIECE:
            tmp->winRate[X_PIECE-1]=1;
            break;
        case O_PIECE:
            tmp->winRate[O_PIECE-1]=1;
            break;
    }
    addBranche2Tree(parent,tmp);
}

void constructFullTree(tree_t t,int level){
    if(!level) return;

    int player = t->next_player;
    board_t b = t->board;

    if((b&0b11)==player){
        creatDecisionTreeNode(t,level,0,1);
        creatDecisionTreeNode(t,level,0,3);
    }

    b>>=2;
    if((b&0b11)==player){
        creatDecisionTreeNode(t,level,1,0);
        creatDecisionTreeNode(t,level,1,2);
        creatDecisionTreeNode(t,level,1,4);
    }

    b>>=2;
    if((b&0b11)==player){
        creatDecisionTreeNode(t,level,2,1);
        creatDecisionTreeNode(t,level,2,5);
    }
    
    b>>=2;
    if((b&0b11)==player){
        creatDecisionTreeNode(t,level,3,0);
        creatDecisionTreeNode(t,level,3,4);
        creatDecisionTreeNode(t,level,3,6);
    }
    b>>=2;
    if((b&0b11)==player){
        creatDecisionTreeNode(t,level,4,1);
        creatDecisionTreeNode(t,level,4,3);
        creatDecisionTreeNode(t,level,4,5);
        creatDecisionTreeNode(t,level,4,7);
    }
    b>>=2;
    if((b&0b11)==player){
        creatDecisionTreeNode(t,level,5,2);
        creatDecisionTreeNode(t,level,5,4);
        creatDecisionTreeNode(t,level,5,8);
    }
    b>>=2;
    if((b&0b11)==player){
        creatDecisionTreeNode(t,level,6,3);
        creatDecisionTreeNode(t,level,6,7);
    }
    b>>=2;
    if((b&0b11)==player){
        creatDecisionTreeNode(t,level,7,4);
        creatDecisionTreeNode(t,level,7,6);
        creatDecisionTreeNode(t,level,7,8);
    }
    b>>=2;
    if((b&0b11)==player){
        creatDecisionTreeNode(t,level,8,5);
        creatDecisionTreeNode(t,level,8,7);
    }
}
void initAI(board_t board, int irole, int icompititor,int i){
    freeTree(searchTree);
    searchTree = creatTree();
    searchTree->board = board;
    searchTree->next_player = irole;
    role = irole;
    compititor = icompititor;
    searchLevel = i;
    constructFullTree(searchTree,i);
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

decision_t makeDecisionAI(){
    
    linkList_t b = searchTree->branches;
    decision_t d = b->next->tree->decision;
    caculateWinRate(searchTree);
    double score = 0;
    while(b->next){
        tree_t t = b->next->tree;
        double iscore = (t->winRate[role-1])*(.45-t->winRate[compititor-1])*(.45-t->winRate[compititor-1])*(.45-t->winRate[compititor-1]);
        if(iscore > score){
            score = iscore;
            d = t->decision;
        }
        b = b->next;
    }
    return d;
}