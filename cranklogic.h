#ifndef CRANKLOGIC_H
#define CRANKLOGIC_H

#include <QObject>
#include "crankdao.h"
#include "cnamedlg.h"
#include "Global.h"

class CRankLogic : public QObject
{
    Q_OBJECT
public:
    explicit CRankLogic(QObject *parent = nullptr);
    void updateRank();
    CRankDao * crankdao;

private:
    int insertIndex();
    void showNameDLg();
    void insertRank(int index);
    CNameDlg * cnamedlg;

private slots:
    void doNameConfirm(const char * name);
};

#endif // CRANKLOGIC_H
