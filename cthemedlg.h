#ifndef CTHEMEDLG_H
#define CTHEMEDLG_H

#include <QMainWindow>
#include "cconfig.h"
#include "cconfiglogic.h"
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QCloseEvent>

namespace Ui {
class CThemeDlg;
}

class CThemeDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CThemeDlg(QWidget *parent = nullptr);
    ~CThemeDlg();
    void initialgemtype();

signals:
    void themeToSet(); //主题设置返回设置的信号
    void set_theme_background_change(QString);
    void set_theme_gem_change(QString);

private slots:
    void doSetToTheme();
    void on_btn_themeToSet_clicked();
    void on_radioButton_Theme_default_clicked();
    void on_radioButton_Theme_custom_clicked();
    void on_toolButton_selsect_backgroundiamgs_clicked();
    void on_btn_theme_confirm_clicked();

private:
    void Theme_default_locking(); //当主题默认时，设置lineedit和toolbutton为锁定状态并初始化lineedit中默认主题的图片路径

private:
    Ui::CThemeDlg *ui;
    CConfig *config = new CConfig();
    //CConfigLogic *configlogic = new CConfigLogic();
    //默认的背景图片的文件路径
    QString backgroundimags_path=":/new/picture/background.bmp";
};

#endif // CTHEMEDLG_H
