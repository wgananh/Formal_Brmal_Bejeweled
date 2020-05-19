#ifndef CGAMEDLG_H
#define CGAMEDLG_H

#include <QMainWindow>
#include "cgamelogic.h"
#include "cconfiglogic.h"
#include "cmenudlg.h"
#include "cranklogic.h"
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

signals:
    void gameToMain();
    void gameToMenu();

private slots:
    void on_btn_gameToMain_clicked();
    void doMainToGame();
    void doMenuToGame();
    void dotheme_background_change(QString); //设置更改后的图片背景，QString为从CThemeDlg传输到CGameDlg的图片路径
    void on_btn_gameToMenu_clicked();

private:
    Ui::CGameDlg *ui;
    CMenuDlg *menu = new CMenuDlg(this);
    CThemeDlg *theme = new CThemeDlg(this);
};

#endif // CGAMEDLG_H
