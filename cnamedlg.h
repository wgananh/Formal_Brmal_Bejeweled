#ifndef CNAMEDLG_H
#define CNAMEDLG_H

#include <QMainWindow>

namespace Ui {
class CNameDlg;
}

class CNameDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CNameDlg(QWidget *parent = nullptr);
    ~CNameDlg();

private:
    Ui::CNameDlg *ui;
};

#endif // CNAMEDLG_H
