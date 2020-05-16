#include "caboutdlg.h"
#include "ui_caboutdlg.h"

CAboutDlg::CAboutDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CAboutDlg)
{
    ui->setupUi(this);
}

CAboutDlg::~CAboutDlg()
{
    delete ui;
}
