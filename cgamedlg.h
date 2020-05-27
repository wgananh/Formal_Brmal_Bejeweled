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
#include <QLabel>
#include <QPixmap>

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
    void clicked();//鼠标点击信号

private slots:
    void on_btn_gameToMain_clicked();
    void doMainToGame();
    void doMenuToGame();
    void on_btn_gameToMenu_clicked();
    void do_theme_background_change(QString);
    void on_pushButton_stop_clicked();
    void update_timebar(); //每隔一秒timebar就更新一次的槽函数
    void Game_start();
    void on_pushButton_continue_clicked();
    void on_pushButton_restart_clicked();
    void mouseClicked();

private:
    Ui::CGameDlg *ui;
    QTimer *timer;
    QImage *image_stop = new QImage(":/new/picture/stop.png"); //游戏暂停的图片
    QLabel *label_stop=new QLabel(this); //存放暂停图片的容器
    CMenuDlg *menu = new CMenuDlg(this);
    CThemeDlg *theme = new CThemeDlg();
    CGameLogic *gamelogic = new CGameLogic();
    QPoint mousePos;//鼠标位置
protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // CGAMEDLG_H
