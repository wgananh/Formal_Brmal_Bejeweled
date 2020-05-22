#include "cmenudlg.h"
#include "ui_cmenudlg.h"

CMenuDlg::CMenuDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMenuDlg)
{
    ui->setupUi(this);
    this->hide();
    connect(parent, SIGNAL(gameToMenu()), this, SLOT(doGameToMenu()));
    CSetDlg *set=new CSetDlg(this);
    connect(set,SIGNAL(setToMenu()),this,SLOT(doSetToMenu()));
    connect(set,SIGNAL(menu_theme_background_change(QString)),this,SLOT(do_theme_background_change(QString)));
}

CMenuDlg::~CMenuDlg()
{
    delete ui;
}


void CMenuDlg::doGameToMenu(){
    this->show();
}

void CMenuDlg::on_btn_menuToGame_clicked()
{
    this->hide();
    emit menuToGame();
}

void CMenuDlg::on_btn_menuToSet_clicked()
{
    this->hide();
    emit menuToSet();
}

void CMenuDlg::doSetToMenu(){
    this->show();
}

void CMenuDlg::do_theme_background_change(QString path){
    emit game_theme_background_change(path);
}
