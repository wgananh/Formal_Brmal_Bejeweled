#ifndef CABOUTDLG_H
#define CABOUTDLG_H

#include <QMainWindow>

namespace Ui {
class CAboutDlg;
}

class CAboutDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CAboutDlg(QWidget *parent = nullptr);
    ~CAboutDlg();

private:
    Ui::CAboutDlg *ui;
};

#endif // CABOUTDLG_H
