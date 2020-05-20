#include "cgamedlg.h"
#include "ui_cgamedlg.h"
#include "cmusicplayer.h"

CGameDlg::CGameDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CGameDlg)
{
    ui->setupUi(this);
    this->hide();
    CMenuDlg *menu = new CMenuDlg(this);
    connect(parent, SIGNAL(mainToGame()), this, SLOT(doMainToGame()));
    connect(menu,SIGNAL(menuToGame()),this,SLOT(doMenuToGame()));

    CMusicPlayer *mus = new CMusicPlayer;
    mus->MusicOn();

    QMediaPlayer *music = new QMediaPlayer();
    music=new QMediaPlayer;
    connect(music,SIGNAL(positionChanged(qint64)),this,SLOT(postitionChanged(qint64)));
    music->setMedia(QUrl::fromLocalFile("D:\\Da Er 2\\Program\\Bejeweled\\bgm.mp3"));
    music->setVolume(80);
    music->play();
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

