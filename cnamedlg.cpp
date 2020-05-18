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

void CNameDlg::on_btn_confirm_clicked()
{
    char * name = new char[50];
    strcpy(name, ui->lineEdit_name->text().toLatin1().toStdString().c_str());
    emit nameConfirm(name);
    this->close();
}

void CNameDlg::closeEvent(QCloseEvent *event)
{
    event->ignore();
    on_btn_confirm_clicked();
}
