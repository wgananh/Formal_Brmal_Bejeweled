#include "csetdlg.h"
#include "ui_csetdlg.h"

CSetDlg::CSetDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CSetDlg)
{
    ui->setupUi(this);
    connect(parent,SIGNAL(menuToSet()),this,SLOT(doMenuToSet()));
}

CSetDlg::~CSetDlg()
{
    delete ui;
}

void CSetDlg::doMenuToSet(){
    this->show();
}

void CSetDlg::on_btn_setToMenu_clicked()
{
    this->hide();
    emit setToMenu();
}
