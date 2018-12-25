#ifndef __AI_H
#define __AI_H
#include "board.h"
#include "data_struct.h"


/* call initAI when AI first make decision */
void initAI(board_t board, int irole, int icompititor, int searchLevel);
/* call forwardAI after AI's compititor move*/
void forwardAI(board_t board,decision_t compititor);
/* searchr for best  decision*/
decision_t makeDecisionAI();

void caculateWinRate(tree_t t);

#endif