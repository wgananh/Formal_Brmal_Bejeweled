#ifndef CGAMEDLG_H
#define CGAMEDLG_H

#include <QMainWindow>
#include "cgamelogic.h"
#include "cconfiglogic.h"
#include "cmenudlg.h"
#include "cranklogic.h"
#include "cthemedlg.h"
#include <QDebug>
#include <QTimer>

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
    void Game_over(); //时间耗尽时游戏结束

signals:
    void gameToMain();
    void gameToMenu();

private slots:
    void on_btn_gameToMain_clicked();
    void doMainToGame();
    void doMenuToGame();
    void on_btn_gameToMenu_clicked();
    void do_theme_background_change(QString);
    void on_pushButton_stop_clicked();
    void update_timebar(); //每隔一秒timebar就更新一次的槽函数
    void on_pushButton_continue_clicked();

private:
    Ui::CGameDlg *ui;
    QTimer *timer;
    CMenuDlg *menu = new CMenuDlg(this);
    CThemeDlg *theme = new CThemeDlg();
    CGameLogic *gamelogic = new CGameLogic();
};

#endif // CGAMEDLG_H
