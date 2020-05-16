#include "chelpdlg.h"
#include "ui_chelpdlg.h"

CHelpDlg::CHelpDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CHelpDlg)
{
    ui->setupUi(this);
}

CHelpDlg::~CHelpDlg()
{
    delete ui;
}
