#include "cgamedlg.h"
#include "ui_cgamedlg.h"
#include "cmusicplayer.h"

CGameDlg::CGameDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CGameDlg)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    this->hide();
    connect(parent, SIGNAL(mainToGame()), this, SLOT(doMainToGame()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update_timebar()));
    connect(parent,SIGNAL(mainToGame()),this,SLOT(Game_start()));
    connect(menu,SIGNAL(menuToGame()),this,SLOT(doMenuToGame()));
    connect(menu,SIGNAL(game_theme_background_change(QString)),this,SLOT(do_theme_background_change(QString)));
    connect(this,SIGNAL(gameToMenu()),this,SLOT(on_pushButton_stop_clicked())); //当点击“菜单”进入menu界面时，游戏自动暂停


    CMusicPlayer *mus = new CMusicPlayer;
    mus->MusicOn();
}

CGameDlg::~CGameDlg()
{
    delete ui;
}

void CGameDlg::on_btn_gameToMain_clicked()
{
    this->hide();
    emit gameToMain();
    Game_over();      //当点击“返回标题”进入bejeweled的最初始界面时，游戏自动结束
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

void CGameDlg::Music(){
    QMediaPlayer *music = new QMediaPlayer();
    music=new QMediaPlayer;
    connect(music,SIGNAL(positionChanged(qint64)),this,SLOT(postitionChanged(qint64)));
    music->setMedia(QUrl::fromLocalFile("bgm.mp3"));
    music->setVolume(20);
    music->play();
}

void CGameDlg::do_theme_background_change(QString path){
    this->setStyleSheet("#CGameDlg{border-image:url("+path+");}");
}

void CGameDlg::update_timebar(){
    int CurrentValue=ui->progressBar_time->value();
    CurrentValue--;
    if(CurrentValue>150&&CurrentValue<=300){
        ui->progressBar_time->setStyleSheet("QProgressBar::chunk { background-color: rgb(0, 255, 0) }");
        ui->progressBar_time->setAlignment(Qt::AlignCenter);
    }
    if(CurrentValue>20&&CurrentValue<=150){
        ui->progressBar_time->setStyleSheet("QProgressBar::chunk { background-color: rgb(255, 255, 0) }");
        ui->progressBar_time->setAlignment(Qt::AlignCenter);
    }
    if(CurrentValue<=20){
        ui->progressBar_time->setStyleSheet("QProgressBar::chunk { background-color: rgb(255, 0, 0) }");
        ui->progressBar_time->setAlignment(Qt::AlignCenter);
    }
    if (CurrentValue<=0){
        Game_over();
    }
    ui->progressBar_time->setValue(CurrentValue);
}

//cgamelog界面显示时游戏开始
void CGameDlg::Game_start(){
    timer->start(1000); //每一秒更新一次timerbar

    gamelogic->setgame_running(true); //初始设置游戏处于运行状态
    gamelogic->BuildMap(5);  //初始化游戏地图

    ui->progressBar_time->setValue(300);
    ui->progressBar_time->setStyleSheet("QProgressBar::chunk { background-color: rgb(0, 255, 0) }");
    ui->progressBar_time->setAlignment(Qt::AlignCenter);
    ui->pushButton_continue->hide(); //初始时"继续游戏"按钮不可见
    ui->pushButton_restart->hide();  //初始时"重新开始"按钮不可见
    ui->pushButton_stop->show(); //初始时"暂停游戏"按钮可见
    ui->pushButton_continue->setEnabled(false); //初始时"继续游戏"按钮不可用
    ui->pushButton_restart->setEnabled(false); //初始时"重新开始"按钮不可用
    ui->pushButton_stop->setEnabled(true); //初始时"暂停游戏"按钮可用
    label_image->hide(); //初始时暂停游戏以及结束的图片都隐藏
}

//时间耗尽，游戏结束
void CGameDlg::Game_over(){
    timer->stop();
    label_image->setGeometry(20,50,400,400);
    label_image->setPixmap(QPixmap::fromImage(*image_gameover));
    label_image->show();
    gamelogic->setgame_running(false);
    ui->pushButton_stop->hide();
    ui->pushButton_stop->setEnabled(false);
    ui->pushButton_continue->hide();
    ui->pushButton_continue->setEnabled(false);
    ui->pushButton_restart->show();
    ui->pushButton_restart->setEnabled(true);

}

void CGameDlg::on_pushButton_stop_clicked()
{
    timer->stop();
    label_image->setGeometry(20,50,400,400);
    label_image->setPixmap(QPixmap::fromImage(*image_stop));
    label_image->show();
    gamelogic->setgame_running(false);
    ui->pushButton_stop->hide();
    ui->pushButton_continue->show();
    ui->pushButton_stop->setEnabled(false);
    ui->pushButton_continue->setEnabled(true);

}

void CGameDlg::on_pushButton_continue_clicked()
{
    timer->start();
    label_image->hide();
    gamelogic->setgame_running(true);
    ui->pushButton_stop->show();
    ui->pushButton_continue->hide();
    ui->pushButton_stop->setEnabled(true);
    ui->pushButton_continue->setEnabled(false);
}

void CGameDlg::on_pushButton_restart_clicked()
{
    timer->start();
    label_image->hide();
    ui->progressBar_time->setValue(300);
    ui->progressBar_time->setStyleSheet("QProgressBar::chunk { background-color: rgb(0, 255, 0) }");
    ui->progressBar_time->setAlignment(Qt::AlignCenter);

    //重新生成地图，待完成
    gamelogic->BuildMap(5);
    gamelogic->setgame_running(true);

    ui->pushButton_restart->hide();
    ui->pushButton_restart->setEnabled(false);
    ui->pushButton_stop->show();
    ui->pushButton_stop->setEnabled(true);

}
