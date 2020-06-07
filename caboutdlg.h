#ifndef CABOUTDLG_H
#define CABOUTDLG_H

#include <QMainWindow>
#include <QDebug>
#include <QDate>
#include <QTime>

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
    QString lastupdatetime;
};

#endif // CABOUTDLG_H
