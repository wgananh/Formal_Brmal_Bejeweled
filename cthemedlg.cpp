#include "cthemedlg.h"
#include "ui_cthemedlg.h"

CThemeDlg::CThemeDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CThemeDlg)
{
    ui->setupUi(this);
    this->hide();
    connect(parent,SIGNAL(setToTheme()),this,SLOT(doSetToTheme()));
}

CThemeDlg::~CThemeDlg()
{
    delete ui;
}

void CThemeDlg::doSetToTheme(){
    this->show();
}

void CThemeDlg::on_btn_themeToSet_clicked()
{
    this->hide();
    emit themeToSet();
}
