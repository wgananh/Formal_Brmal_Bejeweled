#include "cgamedlg.h"
#include "ui_cgamedlg.h"

CGameDlg::CGameDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CGameDlg)
{
    ui->setupUi(this);
    this->hide();
    connect(parent, SIGNAL(mainToGame()), this, SLOT(doMainToGame()));
}

CGameDlg::~CGameDlg()
{
    delete ui;
}

void CGameDlg::on_btn_gameToMain_clicked()
{
    this->hide();
    emit gameToMain();
}

void CGameDlg::doMainToGame()
{
    this->show();
}
