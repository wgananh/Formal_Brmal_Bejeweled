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

    focus=0;
        QString path;
        int i;
        for(i=0;i<5;i++)
            {
                path = ":/new/picture/gem" + QString::number(i+1,10) + ".png";//宝石图片
                pixmap[i].load(path);
            }
            pixmap_di.load(":/new/picture/select.png");//被选中显示
            disappear1.load(":/new/picture/tx1.png");
            disappear2.load(":/new/picture/tx2.png");
            disappear3.load(":/new/picture/tx3.png");//三消的动画过程

    CMusicPlayer *mus = new CMusicPlayer;
    mus->MusicOn();
}

CGameDlg::~CGameDlg()
{
    delete ui;
}


void CGameDlg::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    int num;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            num=gamelogic->m_aMap[i][j];
            //qDebug()<<num;
            //painter.drawPixmap(20+i*50,50+j*50,50,50,pixmap[num-1]);
            painter.drawPixmap(20+j*50,50+i*50,50,50,pixmap[num-1]);
        }
    }
}
void CGameDlg::mousePressEvent(QMouseEvent *ev){
    mouseflag=1;
    int xx;
    int yy;
    xx=ev->x()-20;
    yy=ev->y()-50;
    focus_y=xx/50;
    focus_x=yy/50;
    //qDebug()<<focus_x;
    //qDebug()<<focus_y;
    /*if(focus_x==0&&focus_y==0){
        int temp;
        temp=gamelogic->m_aMap[focus_x][focus_y];
        gamelogic->m_aMap[focus_x][focus_y]=gamelogic->m_aMap[focus_x][focus_y+1];
        gamelogic->m_aMap[focus_x][focus_y+1]=temp;
        this->repaint();
    }*/
    if(focus_x<8){
        if(focus==0){
            point.setX(focus_x);
            point.setY(focus_y);//存下了第一次点击的横纵坐标（换算后的，可以直接用来访问矩阵）
            focus=1;
            //this->repaint();//其实是调用了paintevent
        }else{
            int x=point.x();
            int y=point.y();//取得第一次点击的横纵坐标与新的坐标相比较
            qDebug()<<x;
            qDebug()<<y;
            qDebug()<<focus_x;
            qDebug()<<focus_y;

            if((focus_x==x && (focus_y==y-1 || focus_y==y+1)) || (focus_y == y && (focus_x==x-1 || focus_x==x+1))){//相邻情况（上下左右）==边界？？？
                point1.setX(focus_x);
                point1.setY(focus_y);//把第二次的坐标也存下了，便于后面访问
                focus = 0;//？
                if(focus_x==x&&focus_y==y-1){//第一次选中的宝石要和左边的交换
                    int temp;
                    temp=gamelogic->m_aMap[x][y];
                    gamelogic->m_aMap[x][y]=gamelogic->m_aMap[focus_x][focus_y];
                    gamelogic->m_aMap[focus_x][focus_y]=temp;
                    this->repaint();
                    if(!gamelogic->eliminate(true))
                    {
                        //换回来
                        //
                        //break
                    }
                    while (gamelogic->eliminate()) {
                        eliminateNumber = 0;
                        for(int i = 0; i < 8; i++)
                            for(int j = 0; j < 8; j++)
                            {
                                if(gamelogic->m_aMap[i][j] == 0)
                                {
                                    eliminateNumber++;
                                    //更换图片
                                }
                            }
                        g_rank.nGrade += eliminateNumber*10;//分数增加
                        this->repaint();
                        _sleep(100);
                        for(int i = 0; i < 8; i++)
                            for(int j = 0; j < 8; j++)
                            {
                                if(gamelogic->m_aMap[i][j] == 0)
                                {
                                    //更换图片
                                }
                            }
                        this->repaint();
                        _sleep(100);
                        for(int i = 0; i < 8; i++)
                            for(int j = 0; j < 8; j++)
                            {
                                if(gamelogic->m_aMap[i][j] == 0)
                                {
                                    //更换图片
                                }
                            }
                        this->repaint();
                        _sleep(100);

                        gamelogic->down();
                        this->repaint();
                        _sleep(500);
                        if(gamelogic->hint())
                        {
                            gamelogic->BuildMap(g_spc);
                            this->repaint();
                        }
                    }
                    if(g_rank.nGrade / 1000 != g_spc - 5)
                    {
                        g_spc++;
                        gamelogic->BuildMap(g_spc);
                        this->repaint();
                    }
                }else if(focus_x==x&&focus_y==y+1){//第一次选中的宝石要和右边的交换11
                    int temp;
                    temp=gamelogic->m_aMap[x][y];
                    gamelogic->m_aMap[x][y]=gamelogic->m_aMap[focus_x][focus_y];
                    gamelogic->m_aMap[focus_x][focus_y]=temp;
                    this->repaint();
                    while (gamelogic->eliminate()) {
                        this->repaint();
                        _sleep(500);
                        gamelogic->down();
                        this->repaint();
                        _sleep(500);
                    }
                }else if(focus_x==x-1&&focus_y==y){//第一次选中的宝石要和上边的交换
                    int temp;
                    temp=gamelogic->m_aMap[x][y];
                    gamelogic->m_aMap[x][y]=gamelogic->m_aMap[focus_x][focus_y];
                    gamelogic->m_aMap[focus_x][focus_y]=temp;
                    this->repaint();
                    while (gamelogic->eliminate()) {
                        this->repaint();
                        _sleep(500);
                        gamelogic->down();
                        this->repaint();
                        _sleep(500);
                    }
                }else if(focus_x==x+1&&focus_y==y){//第一次选中的宝石要和下边的交换
                    int temp;
                    temp=gamelogic->m_aMap[x][y];
                    gamelogic->m_aMap[x][y]=gamelogic->m_aMap[focus_x][focus_y];
                    gamelogic->m_aMap[focus_x][focus_y]=temp;
                    this->repaint();
                    while (gamelogic->eliminate()) {
                        this->repaint();
                        _sleep(500);
                        gamelogic->down();
                        this->repaint();
                        _sleep(500);
                    }
                }
            }
        }
    }

}
void CGameDlg::mouseReleaseEvent(QMouseEvent *ev){

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
    gamelogic->BuildMap(g_spc);  //初始化游戏地图

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
    gamelogic->BuildMap(g_spc);
    gamelogic->setgame_running(true);

    ui->pushButton_restart->hide();
    ui->pushButton_restart->setEnabled(false);
    ui->pushButton_stop->show();
    ui->pushButton_stop->setEnabled(true);

}
