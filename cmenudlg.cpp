#include "cmenudlg.h"
#include "ui_cmenudlg.h"

CMenuDlg::CMenuDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMenuDlg)
{
    ui->setupUi(this);
    this->hide();
    connect(parent, SIGNAL(gameToMenu()), this, SLOT(doGameToMenu()));
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
