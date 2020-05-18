#include "cranklogic.h"

CRankLogic::CRankLogic(QObject *parent) : QObject(parent)
{
    QObject::connect(cnamedlg, SIGNAL(nameConfirm(const char*)), this, SLOT(doNameConfirm(const char*)));
}

void CRankLogic::showNameDLg()
{
    cnamedlg = new CNameDlg();
    cnamedlg->show();
}

void CRankLogic::doNameConfirm(const char * name)
{
    strcpy(g_rank.strName, name);
    delete [] name;
}
