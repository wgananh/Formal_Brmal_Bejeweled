#include "cthemedlg.h"
#include "ui_cthemedlg.h"

CThemeDlg::CThemeDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CThemeDlg)
{
    ui->setupUi(this);
}

CThemeDlg::~CThemeDlg()
{
    delete ui;
}
