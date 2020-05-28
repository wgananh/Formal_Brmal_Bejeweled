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
    explicit CRankDlg(QWidget *parent = nullptr);
    void showRank();
    ~CRankDlg();

private slots:
    void on_actionClear_triggered();
private:
    Ui::CRankDlg *ui;
    int ranknum;

};

#endif // CRANKDLG_H
