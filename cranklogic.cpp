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
    int length = crankdao->getRank();
    int index;
    for(index = length; index > 0; index--)
        if(g_rank.nGrade < ranks[index - 1]->nGrade)
            break;
        else
            continue;
    return index;
}


void CRankLogic::insertIndex(int rankIndex)
{
    if(rankIndex == 10)
        return;
    int moveNumber = 9 - rankIndex;
    delete ranks[9];
    for(int i = 0; i < moveNumber; i++)
    {
//        ranks[9 - i]->nTime = ranks[8 - i]->nTime;
//        ranks[9 - i]->nGrade = ranks[8 - i]->nGrade;
//        strcpy(ranks[9 - i]->strName, ranks[8 - i]->strName);
        ranks[9 - i] = ranks[8 - i];
    }
    ranks[rankIndex] = new RANKINFOR();
    ranks[rankIndex]->nTime = g_rank.nTime;
    ranks[rankIndex]->nGrade = g_rank.nGrade;
    if(g_rank.strName[0] == 0)
        g_rank.strName[0] = '-';
    strcpy(ranks[rankIndex]->strName, g_rank.strName);
    crankdao->saveRank();
}
