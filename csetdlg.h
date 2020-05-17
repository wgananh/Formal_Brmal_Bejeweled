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

private slots:
    void doMenuToSet();
    void on_btn_setToMenu_clicked();
};

#endif // CSETDLG_H
