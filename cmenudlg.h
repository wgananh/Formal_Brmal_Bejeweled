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

private:
    Ui::CMenuDlg *ui;
};

#endif // CMENUDLG_H
