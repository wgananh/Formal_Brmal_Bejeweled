#include "cbejeweleddlg.h"
#include "ui_cbejeweleddlg.h"

CBejeweledDlg::CBejeweledDlg(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CBejeweledDlg)
{
    ui->setupUi(this);
    CGameDlg *game = new CGameDlg(this);

    connect(game, SIGNAL(gameToMain()), this, SLOT(doGameToMain()));
}

CBejeweledDlg::~CBejeweledDlg()
{
    delete ui;
}


void CBejeweledDlg::on_btn_mainToGame_clicked()
{
    this->hide();
    emit mainToGame();
}

void CBejeweledDlg::doGameToMain()
{
    this->show();
}
