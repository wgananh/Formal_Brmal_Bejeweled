#include "csetdlg.h"
#include "ui_csetdlg.h"

CSetDlg::CSetDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CSetDlg)
{
    ui->setupUi(this);
    this->hide();
    CThemeDlg *theme = new CThemeDlg(this);
    connect(parent,SIGNAL(menuToSet()),this,SLOT(doMenuToSet()));
    connect(theme,SIGNAL(themeToSet()),this,SLOT(doThemeToSet()));
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

void CSetDlg::on_btn_setToTheme_clicked()
{
    this->hide();
    emit setToTheme();
}

void CSetDlg::doThemeToSet(){
    this->show();
}
