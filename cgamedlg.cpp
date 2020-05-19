#include "cgamedlg.h"
#include "ui_cgamedlg.h"

CGameDlg::CGameDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CGameDlg)
{
    ui->setupUi(this);
    this->hide();
    connect(parent, SIGNAL(mainToGame()), this, SLOT(doMainToGame()));
    connect(menu,SIGNAL(menuToGame()),this,SLOT(doMenuToGame()));
    connect(theme,SIGNAL(theme_background_change(QString)),this,SLOT(dotheme_background_change(QString)));
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

void CGameDlg::dotheme_background_change(QString backgroundimags_path){
    qDebug()<<backgroundimags_path;
    this->setStyleSheet("#CGameDlg{border-image: url("+backgroundimags_path+");}");
}
