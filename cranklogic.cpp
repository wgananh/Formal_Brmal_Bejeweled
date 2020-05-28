#include "cranklogic.h"

CRankLogic::CRankLogic(QObject *parent) : QObject(parent)
{
    crankdao = new CRankDao();
}

void CRankLogic::updateRank()
{
    crankdao->getRank();
}

int CRankLogic::getIndex()
{
    for(int i = 0; ranks[i] != 0; i++)
        if(g_rank.nGrade >= (*ranks[i]).nGrade)
        {
            return i;
            break;
        }
        else
            continue;
    return -1;
}


void CRankLogic::insertIndex(int rankIndex)
{
    if(rankIndex == -1)
        return;
    int moveNumber = 9 - rankIndex;
    for(int i = 0; i < moveNumber; i++)
    {
        ranks[9 - i]->nTime = ranks[8 - i]->nTime;
        ranks[9 - i]->nGrade = ranks[8 - i]->nGrade;
        strcpy(ranks[9 - i]->strName, ranks[8 - i]->strName);
    }
    ranks[rankIndex]->nTime = g_rank.nTime;
    ranks[rankIndex]->nGrade = g_rank.nGrade;
    strcpy(ranks[rankIndex]->strName, g_rank.strName);
    crankdao->saveRank();
}
