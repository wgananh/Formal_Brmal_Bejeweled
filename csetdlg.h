#ifndef CSETDLG_H
#define CSETDLG_H

#include <QMainWindow>
#include <QCloseEvent>
#include "cmusicdlg.h"
#include "cconfiglogic.h"
#include "cthemedlg.h"

namespace Ui {
class CSetDlg;
}

class CSetDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CSetDlg(QWidget *parent = nullptr);
    ~CSetDlg();


private:
    Ui::CSetDlg *ui;
    CMusicDlg *music;
    CThemeDlg *theme;
    void closeEvent(QCloseEvent *event);

signals:
    void setToMenu();
    void setToTheme();
    void menu_theme_background_change(QString);
    void menu_theme_gem_change(QString);
    void menu_music_background_change(QString);

private slots:
    void doMenuToSet();
    void on_btn_setToMenu_clicked();
    void on_btn_setToTheme_clicked();
    void doThemeToSet();
    void doMusicToSet();
    void on_btn_setToMusic_clicked();
    void do_theme_background_change(QString);
    void do_theme_gem_change(QString);
    void do_music_background_change(QString);
};

#endif // CSETDLG_H
