#include "cnamedlg.h"
#include "ui_cnamedlg.h"

CNameDlg::CNameDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CNameDlg)
{
    ui->setupUi(this);
}

CNameDlg::~CNameDlg()
{
    delete ui;
}
