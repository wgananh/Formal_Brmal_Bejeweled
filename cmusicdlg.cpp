#include "cmusicdlg.h"
#include "ui_cmusicdlg.h"

CMusicDlg::CMusicDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMusicDlg)
{
    ui->setupUi(this);
}

CMusicDlg::~CMusicDlg()
{
    delete ui;
}
