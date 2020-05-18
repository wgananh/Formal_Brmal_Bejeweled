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
    ~CRankDlg();

private:
    Ui::CRankDlg *ui;

};

#endif // CRANKDLG_H
