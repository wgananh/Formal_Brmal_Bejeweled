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
    void gameToMenu();

private slots:
    void on_btn_gameToMain_clicked();
    void doMainToGame();
    void doMenuToGame();
    void on_btn_gameToMenu_clicked();

private:
    Ui::CGameDlg *ui;
};

#endif // CGAMEDLG_H
