#ifndef CGAMEDLG_H
#define CGAMEDLG_H

#include <QMainWindow>
#include "cgamelogic.h"
#include "cconfiglogic.h"
#include "cmenudlg.h"
#include "cranklogic.h"

namespace Ui {
class CGameDlg;
}

class CGameDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CGameDlg(QWidget *parent = nullptr);
    ~CGameDlg();

signals:
    void gameToMain();

private slots:
    void on_btn_gameToMain_clicked();
    void doMainToGame();
private:
    Ui::CGameDlg *ui;
};

#endif // CGAMEDLG_H
