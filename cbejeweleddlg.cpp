#include "cbejeweleddlg.h"
#include "ui_cbejeweleddlg.h"

CBejeweledDlg::CBejeweledDlg(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CBejeweledDlg)
{
    ui->setupUi(this);

    game = new CGameDlg(this);
    rank = new CRankDlg(this);
    name = new CNameDlg(this);
    connect(game, SIGNAL(gameToMain()), this, SLOT(doGameToMain()));
    connect(name, SIGNAL(nameConfirm()), this, SLOT(doNameConfirm()));
    ui->label_welcome->setText("您好！请先设置姓名");
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

void CBejeweledDlg::on_btn_mainToRank_clicked()
{
    rank->showRank();
}

void CBejeweledDlg::doNameConfirm()
{
    this->ui->label_welcome->setText("欢迎您，" + QString::fromStdString(g_rank.strName));
}

void CBejeweledDlg::on_btn_name_clicked()
{
    name->show();
}
