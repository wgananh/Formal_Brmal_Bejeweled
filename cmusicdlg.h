#ifndef CMUSICDLG_H
#define CMUSICDLG_H

#include <QMainWindow>
#include "cconfig.h"

namespace Ui {
class CMusicDlg;
}

class CMusicDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMusicDlg(QWidget *parent = nullptr);
    ~CMusicDlg();

private:
    Ui::CMusicDlg *ui;
};

#endif // CMUSICDLG_H
