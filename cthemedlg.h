#ifndef CTHEMEDLG_H
#define CTHEMEDLG_H

#include <QMainWindow>
#include "cconfig.h"
#include <QFileDialog>
#include <QFile>
#include <QDebug>

namespace Ui {
class CThemeDlg;
}

class CThemeDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CThemeDlg(QWidget *parent = nullptr);
    ~CThemeDlg();

signals:
    void themeToSet();

private slots:
    void doSetToTheme();

    void on_btn_themeToSet_clicked();

    void on_radioButton_Theme_default_clicked();

    void on_radioButton_Theme_custom_clicked();

    void on_toolButton_selsect_backgroundiamgs_clicked();

    void on_toolButton_selsect_gemimags_clicked();

    void on_toolButton_selsect_maskimags_clicked();


private:
    void Theme_default_locking(); //当主题默认时，设置lineedit和toolbutton为锁定状态并初始化lineedit中默认主题的图片路径

private:
    Ui::CThemeDlg *ui;

    //自定义时，用户选择的背景图片、宝石图片、掩码图片的文件路径
    QString backgroundimags_path="/new/picture/background.bmp"
            ,gemimags_path="/new/picture/gem1.bmp,gem2.bmp,gem3.bmp,gem4.bmp,gem5.bmp,gem6.bmp,gem7.bmp,gem8.bmp"
            ,maskiamgs_path;
};

#endif // CTHEMEDLG_H
