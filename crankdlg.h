#ifndef CRANKDLG_H
#define CRANKDLG_H

#include <QMainWindow>
#include "cranklogic.h"

namespace Ui {
class CRankDlg;
}

class CRankDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CRankDlg(QWidget *parent = nullptr);
    void showRank();
    ~CRankDlg();

private:
    CRankLogic * cranklogic;
    Ui::CRankDlg *ui;

private slots:

};

#endif // CRANKDLG_H
