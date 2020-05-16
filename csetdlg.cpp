#include "csetdlg.h"
#include "ui_csetdlg.h"

CSetDlg::CSetDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CSetDlg)
{
    ui->setupUi(this);
}

CSetDlg::~CSetDlg()
{
    delete ui;
}
