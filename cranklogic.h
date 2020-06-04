#ifndef CRANKLOGIC_H
#define CRANKLOGIC_H

#include <QObject>
#include "crankdao.h"
#include"crankdlg.h"
#include "Global.h"

class CRankLogic : public QObject
{
    Q_OBJECT
public:
    explicit CRankLogic(QObject *parent = nullptr);
    void updateRank();
    int getIndex();
    void insertIndex(int rankIndex);
    CRankDao * crankdao;
    CRankDlg * crankdlg;

};

#endif // CRANKLOGIC_H
