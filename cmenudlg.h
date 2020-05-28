#ifndef CMENUDLG_H
#define CMENUDLG_H

#include <QMainWindow>
#include "csetdlg.h"

namespace Ui {
class CMenuDlg;
}

class CMenuDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMenuDlg(QWidget *parent = nullptr);
    ~CMenuDlg();

signals:
    void menuToGame();
    void menuToSet();
    void game_theme_background_change(QString);
    void game_theme_gem_change(QString);

private slots:
    void doGameToMenu();

    void on_btn_menuToGame_clicked();

    void on_btn_menuToSet_clicked();

    void doSetToMenu();

    void do_theme_background_change(QString);
    void do_theme_gem_change(QString);

private:
    Ui::CMenuDlg *ui;
};

#endif // CMENUDLG_H
