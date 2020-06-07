#ifndef CHELPDLG_H
#define CHELPDLG_H

#include <QMainWindow>

namespace Ui {
class CHelpDlg;
}

class CHelpDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CHelpDlg(QWidget *parent = nullptr);
    ~CHelpDlg();


private:
    Ui::CHelpDlg *ui;
};

#endif // CHELPDLG_H
