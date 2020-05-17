#include "cgamedlg.h"
#include "ui_cgamedlg.h"

CGameDlg::CGameDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CGameDlg)
{
    ui->setupUi(this);
    this->hide();
    CMenuDlg *menu = new CMenuDlg(this);
    connect(parent, SIGNAL(mainToGame()), this, SLOT(doMainToGame()));
    connect(menu,SIGNAL(doMenuToGame()),this,SLOT(doMenuToGame()));
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


void CGameDlg::on_btn_gameToMenu_clicked()
{
    this->hide();
    emit gameToMenu();
}

void CGameDlg::doMenuToGame(){
    this->show();
}
