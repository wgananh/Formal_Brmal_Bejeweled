#ifndef CSETDLG_H
#define CSETDLG_H

#include <QMainWindow>
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

signals:
    void setToMenu();
    void setToTheme();

private slots:
    void doMenuToSet();
    void on_btn_setToMenu_clicked();
    void on_btn_setToTheme_clicked();
    void doThemeToSet();
};

#endif // CSETDLG_H
