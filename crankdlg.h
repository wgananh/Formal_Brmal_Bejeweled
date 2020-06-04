#ifndef CRANKDLG_H
#define CRANKDLG_H

#include <QMainWindow>
#include <crankdao.h>

namespace Ui {
class CRankDlg;
}

class CRankDlg : public QMainWindow
{
    Q_OBJECT

public:
    static CRankDlg * getCRankDlg();
    void showRank();
    ~CRankDlg();

private slots:
    void on_actionClear_triggered();

private:
    explicit CRankDlg(QWidget *parent = nullptr);
    static CRankDlg * crankdlg;
    Ui::CRankDlg *ui;
    int ranknum;
};
#endif // CRANKDLG_H
