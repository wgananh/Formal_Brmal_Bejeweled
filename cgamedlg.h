#ifndef CGAMEDLG_H
#define CGAMEDLG_H

#include <QMainWindow>
#include "cgamelogic.h"
#include "cconfiglogic.h"
#include "cmenudlg.h"
#include "cranklogic.h"
#include "cthemedlg.h"
#include <QDebug>

namespace Ui {
class CGameDlg;
}

class CGameDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CGameDlg(QWidget *parent = nullptr);
    ~CGameDlg();

    void Music();

signals:
    void gameToMain();
    void gameToMenu();

private slots:
    void on_btn_gameToMain_clicked();
    void doMainToGame();
    void doMenuToGame();
    void on_btn_gameToMenu_clicked();
    void do_theme_background_change(QString);


private:
    Ui::CGameDlg *ui;
    CMenuDlg *menu = new CMenuDlg(this);
    CThemeDlg *theme = new CThemeDlg();
};

#endif // CGAMEDLG_H
