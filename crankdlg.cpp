#include "crankdlg.h"
#include "ui_crankdlg.h"

CRankDlg::CRankDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CRankDlg)
{
    ui->setupUi(this);
}

CRankDlg::~CRankDlg()
{
    delete ui;
}
