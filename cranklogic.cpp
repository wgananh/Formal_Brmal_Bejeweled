#include "cranklogic.h"

CRankLogic::CRankLogic(QObject *parent) : QObject(parent)
{
    crankdao = new CRankDao();
    cnamedlg = new CNameDlg();
    QObject::connect(cnamedlg, SIGNAL(nameConfirm(const char*)), this, SLOT(doNameConfirm(const char*)));
}

void CRankLogic::updateRank()
{
    crankdao->getRank();
}

int CRankLogic::insertIndex()
{
    int i = 0;
    for(; i < crankdao->totalNumber; i++)
        if(g_rank.nTime > (*crankdao->ranks[i]).nTime)
            return i;
        else if(g_rank.nTime < (*crankdao->ranks[i]).nTime)
            continue;
        else
            for(; i < crankdao->totalNumber; i++)
                if(g_rank.nGrade > (*crankdao->ranks[i]).nGrade)
                    continue;
                else
                    return i;
    return -1;
}

void CRankLogic::showNameDLg()
{
    cnamedlg->show();
}

void CRankLogic::insertRank(int index)
{
    int moveNumber = 9 - index;
    for(int i = 0; i < moveNumber; i++)
        crankdao->ranks[9 - i] = crankdao->ranks[8 - i];
    crankdao->ranks[index] = &g_rank;
    crankdao->saveRank();
}

void CRankLogic::doNameConfirm(const char * name)
{
    strcpy(g_rank.strName, name);
    delete [] name;
}
