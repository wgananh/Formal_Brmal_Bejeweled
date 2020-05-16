#include "cmenudlg.h"
#include "ui_cmenudlg.h"

CMenuDlg::CMenuDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMenuDlg)
{
    ui->setupUi(this);
}

CMenuDlg::~CMenuDlg()
{
    delete ui;
}
