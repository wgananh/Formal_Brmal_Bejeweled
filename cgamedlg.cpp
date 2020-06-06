#include "cgamedlg.h"
#include "ui_cgamedlg.h"
#include "cmusicplayer.h"

CGameDlg::CGameDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CGameDlg)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(parent, SIGNAL(mainToGame()), this, SLOT(doMainToGame()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update_timebar()));
    connect(menu,SIGNAL(menuToGame()),this,SLOT(doMenuToGame()));
    connect(menu,SIGNAL(game_theme_background_change(QString)),this,SLOT(do_theme_background_change(QString)));
    connect(menu,SIGNAL(game_theme_gem_change(QString)),this,SLOT(do_theme_gem_change(QString)));
    connect(this,SIGNAL(gameToMenu()),this,SLOT(on_pushButton_stop_clicked())); //当点击“菜单”进入menu界面时，游戏自动暂停
    connect(ui->pushButton_hint,SIGNAL(clicked()),this,SLOT(do_btn_hint()));

    focus=0;
    //gemtype="gem";
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            isSelected[i][j]=0;//初始化为未被选中
            midSituation[i][j]=0;//状态为0
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            gamelogic->point[i][j]=-1;
        }
    }
    QString path;
    int i;
    for(i=0;i<8;i++)
    {
        path = ":/new/picture/gem"  + QString::number(i+1,10) + ".png";//宝石图片
        pixmap[i].load(path);
    }
    for(i=0;i<10;i++)
    {
        path = ":/new/picture/number" + QString::number(i,10) + ".png";//宝石图片
        number[i].load(path);
    }
    circle.load(":/new/picture/circle.png");
    pixmap_di.load(":/new/picture/select.png");//被选中显示
    disappear1.load(":/new/picture/tx1.png");
    disappear2.load(":/new/picture/tx2.png");
    disappear3.load(":/new/picture/tx3.png");//三消的动画过程
    disappear3.load(":/new/picture/tx3.png");



    //音乐按钮图片
    QIcon icoOn(":/music on.png");
    QIcon icoOff(":/music off.png");
    ui->pushButton->setIcon(icoOn);
    ui->pushButton_2->setIcon(icoOff);
    ui->pushButton->setIconSize(QSize(50,50));
    ui->pushButton->setFlat(true);
    ui->pushButton_2->setIconSize(QSize(50,50));
    ui->pushButton_2->setFlat(true);
    if(music==1){
        mus->MusicOn();
    }else{
        mus->MusicOff();
    }

}

CGameDlg::~CGameDlg()
{
    delete ui;
}


void CGameDlg::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    int num;
    painter.drawPixmap(510,55,100,100,circle);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            num=gamelogic->m_aMap[i][j];
            //qDebug()<<num;
            //painter.drawPixmap(20+i*50,50+j*50,50,50,pixmap[num-1]);
            painter.drawPixmap(20+j*50,50+i*50,50,50,pixmap[num-1]);
            if(isSelected[i][j]==1){//被选中的框
                painter.drawPixmap(20+j*50,50+i*50,50,50,pixmap_di);
                isSelected[i][j]=0;
            }
            if(i==gamelogic->point[0][0]&&j==gamelogic->point[0][1]){//提示的框
                painter.drawPixmap(20+j*50,50+i*50,50,50,pixmap_di);
                gamelogic->point[0][0]=gamelogic->point[0][1]=-1;//初始化
            }
            if(i==gamelogic->point[1][0]&&j==gamelogic->point[1][1]){
                painter.drawPixmap(20+j*50,50+i*50,50,50,pixmap_di);
                gamelogic->point[1][0]=gamelogic->point[1][1]=-1;//初始化
            }
            if(midSituation[i][j]==1){
                painter.drawPixmap(20+j*50,50+i*50,50,50,disappear1);
            }else if(midSituation[i][j]==2){
                painter.drawPixmap(20+j*50,50+i*50,50,50,disappear2);
            }else if(midSituation[i][j]==3){
                painter.drawPixmap(20+j*50,50+i*50,50,50,disappear3);
                //加分动画
                if(addScoreSituation==0){
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1,40+i*50-(addScoreSituation+1)*1,20,30,number[1]);
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1+20,40+i*50-(addScoreSituation+1)*1,20,30,number[0]);
                }else if(addScoreSituation==1){
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1,40+i*50-(addScoreSituation+1)*1,10,20,number[1]);
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1+20,40+i*50-(addScoreSituation+1)*1,10,20,number[0]);
                }else if(addScoreSituation==2){
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1,40+i*50-(addScoreSituation+1)*1,10,20,number[1]);
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1+20,40+i*50-(addScoreSituation+1)*1,10,20,number[0]);
                }else if(addScoreSituation==3){
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1,40+i*50-(addScoreSituation+1)*1,10,20,number[1]);
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1+20,40+i*50-(addScoreSituation+1)*1,10,20,number[0]);
                }else if(addScoreSituation==4){
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1,40+i*50-(addScoreSituation+1)*1,10,20,number[1]);
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1+20,40+i*50-(addScoreSituation+1)*1,10,20,number[1]);
                }else if(addScoreSituation==5){
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1,40+i*50-(addScoreSituation+1)*1,10,20,number[1]);
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1+20,40+i*50-(addScoreSituation+1)*1,10,20,number[0]);
                }else if(addScoreSituation==6){
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1,40+i*50-(addScoreSituation+1)*1,10,20,number[1]);
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1+20,40+i*50-(addScoreSituation+1)*1,10,20,number[0]);
                }else if(addScoreSituation==7){
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1,40+i*50-(addScoreSituation+1)*1,10,20,number[1]);
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1+20,40+i*50-(addScoreSituation+1)*1,10,20,number[0]);
                }else if(addScoreSituation==8){
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1,40+i*50-(addScoreSituation+1)*1,10,20,number[1]);
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1+20,40+i*50-(addScoreSituation+1)*1,10,20,number[0]);
                }else if(addScoreSituation==9){
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1,40+i*50-(addScoreSituation+1)*1,10,20,number[1]);
                    painter.drawPixmap(30+j*50+(addScoreSituation+1)*1+20,40+i*50-(addScoreSituation+1)*1,10,20,number[0]);
                }
                midSituation[i][j]=0;
            }
        }
    }
    for(int i=0;i<string_grade.length();i++){
        painter.drawPixmap(530+i*20,80,20,50,number[string_grade[i]-48]);//计分板图片更新
    }
    if(eli_music==1){
        //mus1->Music_eliminate();
        eli_music=0;
    }
}
void CGameDlg::mousePressEvent(QMouseEvent *ev){
    int eli_number=0;
    if(!gamelogic->game_running)return;
    QPainter painter(this);
    mouseflag=1;
    int xx;
    int yy;
    xx=ev->x()-20;
    yy=ev->y()-50;
    focus_y=xx/50;
    focus_x=yy/50;//把点击的坐标翻译成了宝石矩阵的行列号，便于下面访问算法
    if(focus_x<8&&focus_y<8){//仅在8*8宝石范围内相应鼠标点击事件
        if(focus==0){
            point.setX(focus_x);
            point.setY(focus_y);//存下了第一次点击的横纵坐标（换算后的，可以直接用来访问矩阵）
            isSelected[focus_x][focus_y]=1;
            focus=1;
            this->repaint();//其实是调用了paintevent
        }


        //道具部分
        if(props){
            if(boom){
                gamelogic->propsEliminate(1,focus_x,focus_y);
                ui->label_boom->setText(QString::number(g_props_boom));
                props=false;
                boom=false;
            }
            if(cross){
                gamelogic->propsEliminate(2,focus_x,focus_y);
                ui->label_cross->setText(QString::number(g_props_cross));
                props=false;
                cross=false;
            }
            if(color){
                gamelogic->propsEliminate(3,focus_x,focus_y);
                ui->label_color->setText(QString::number(g_props_color));
                props=false;
                color=false;
            }

            //            while(gamelogic->down()){
            //                mus->Music_down();
            //                this->repaint();
            //                _sleep(100);
            //            }


            do{
                eli_music=1;
                eliminateNumber = 0;
                for(int i = 0; i < 8; i++){
                    for(int j = 0; j < 8; j++)
                    {
                        if(gamelogic->m_aMap[i][j] == 0)
                        {
                            eliminateNumber++;//这个是0的个数 消除数
                            midSituation[i][j]=1;//状态1
                        }
                    }
                }
                eli_number+=eliminateNumber;
                g_rank.nGrade += eliminateNumber*5;//分数增加
                string_grade=std::to_string(g_rank.nGrade);

                //消除宝石的音效
                mus->Music_eliminate();

                this->repaint();
                _sleep(100);
                for(int i = 0; i < 8; i++){
                    for(int j = 0; j < 8; j++)
                    {
                        if(gamelogic->m_aMap[i][j] == 0)
                        {
                            //更换图片
                            midSituation[i][j]=2;//状态1

                        }
                    }
                }
                this->repaint();
                _sleep(100);
                for(int i = 0; i < 8; i++){
                    for(int j = 0; j < 8; j++)
                    {
                        if(gamelogic->m_aMap[i][j] == 0)
                        {
                            //更换图片
                            midSituation[i][j]=3;//状态1
                        }
                    }
                }
                ui->label_boom->setText(QString::number(g_props_boom));
                ui->label_cross->setText(QString::number(g_props_cross));
                ui->label_color->setText(QString::number(g_props_color));
                this->repaint();
                _sleep(100);
                //                for(int k=0;k<10;k++){
                //                    addScoreSituation=k;
                //                    this->repaint();
                //                    _sleep(25);
                //                }
                while(gamelogic->down()){
                    mus->Music_down();
                    this->repaint();
                    _sleep(100);
                }
            } while(gamelogic->eliminate());
        }

        else{
            int x=point.x();
            int y=point.y();//取得第一次点击的横纵坐标与新的坐标相比较
            isSelected[focus_x][focus_y]=1;
            this->repaint();
            //painter.drawPixmap(20+focus_y*50,50+focus_x*50,50,50,pixmap_di);

            if((focus_x==x && (focus_y==y-1 || focus_y==y+1)) || (focus_y == y && (focus_x==x-1 || focus_x==x+1))){//相邻情况（上下左右）==边界？？？
                point1.setX(focus_x);
                point1.setY(focus_y);//把第二次的坐标也存下了，便于后面访问
                focus = 0;//标志


                int temp;
                temp=gamelogic->m_aMap[x][y];
                gamelogic->m_aMap[x][y]=gamelogic->m_aMap[focus_x][focus_y];
                gamelogic->m_aMap[focus_x][focus_y]=temp;
                this->repaint();
                _sleep(100);
                if(!gamelogic->eliminate(true))//点的两个不能交换
                {
                    //换回来
                    int temp1;
                    temp1=gamelogic->m_aMap[x][y];
                    gamelogic->m_aMap[x][y]=gamelogic->m_aMap[focus_x][focus_y];
                    gamelogic->m_aMap[focus_x][focus_y]=temp1;
                    this->repaint();
                    _sleep(100);

                }
                while (gamelogic->eliminate()){
                    eli_music=1;
                    eliminateNumber = 0;
                    for(int i = 0; i < 8; i++){
                        for(int j = 0; j < 8; j++)
                        {
                            if(gamelogic->m_aMap[i][j] == 0)
                            {
                                eliminateNumber++;//这个是0的个数 消除数
                                midSituation[i][j]=1;//状态1
                            }
                        }
                    }
                    eli_number+=eliminateNumber;
                    g_rank.nGrade += eliminateNumber*10;//分数增加
                    string_grade=std::to_string(g_rank.nGrade);

                    //消除宝石的音效
                    mus->Music_eliminate();

                    this->repaint();
                    _sleep(100);
                    for(int i = 0; i < 8; i++){
                        for(int j = 0; j < 8; j++)
                        {
                            if(gamelogic->m_aMap[i][j] == 0)
                            {
                                //更换图片
                                midSituation[i][j]=2;//状态2

                            }
                        }
                    }
                    this->repaint();
                    _sleep(100);
                    for(int i = 0; i < 8; i++){
                        for(int j = 0; j < 8; j++)
                        {
                            if(gamelogic->m_aMap[i][j] == 0)
                            {
                                //更换图片
                                midSituation[i][j]=3;//状态3
                            }
                        }
                    }
                    ui->label_boom->setText(QString::number(g_props_boom));
                    ui->label_cross->setText(QString::number(g_props_cross));
                    ui->label_color->setText(QString::number(g_props_color));
                    this->repaint();
                    _sleep(100);
                    for(int k=0;k<10;k++){
                        addScoreSituation=k;
                        this->repaint();
                        _sleep(25);
                    }

                    while(gamelogic->down()){
                        mus->Music_down();
                        this->repaint();
                        _sleep(100);
                    }
                }

            }
            else{
                point.setX(focus_x);
                point.setY(focus_y);
            }
        }
        //连消的音效播放
        if(eli_number==5){//五连消
            mus1->Music_great();
        }
        if(eli_number>5&&eli_number<=7){ //6、7连消
            mus1->Music_excellent();
        }
        if(eli_number>7&&eli_number<=9){ //8、9连消
            mus1->Music_amazing();
        }
        if(eli_number>9){//时间奖励，连续消去10个及以上的宝石，时间加5秒
            mus1->Music_unbelievable();
            ui->progressBar_time->setValue(ui->progressBar_time->value()+5);
        }
        if(g_rank.nGrade / 1000 != g_spc - 5)//确定等级
        {
            if(g_spc<8){
                g_spc++;
                gamelogic->BuildMap(g_spc);
                this->repaint();
            }
        }
        if(gamelogic->hint()==0)//当前整个地图没有可以交换产生三连->重新构图
        {
            gamelogic->BuildMap(g_spc);
            this->repaint();
        }
    }
}



void CGameDlg::do_btn_hint(){
    gamelogic->hint();//这里更新了point[2][2]数组
    g_rank.nGrade-=30;
    this->repaint();
}

void CGameDlg::on_btn_gameToMain_clicked()
{
    this->hide();
    Game_over(false);      //当点击“返回标题”进入bejeweled的最初始界面时，游戏自动结束
    emit gameToMain();
}

void CGameDlg::doMainToGame()
{
    this->show();
    this->setDisabled(false);
    this->Game_start();
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


void CGameDlg::do_theme_gem_change(QString path){
    gemtype=path;
    int i;
    for(i=0;i<8;i++)
    {
        path = ":/new/picture/" + gemtype + QString::number(i+1,10) + ".png";//宝石图片
        pixmap[i].load(path);
    }
    this->repaint();
    qDebug()<<gemtype;
}

void CGameDlg::update_timebar(){
    int CurrentValue=ui->progressBar_time->value();
    CurrentValue--;
    if(CurrentValue>(totaltime/2)&&CurrentValue<=totaltime){
        ui->progressBar_time->setStyleSheet("QProgressBar::chunk { background-color: rgb(0, 255, 0) }");
        ui->progressBar_time->setAlignment(Qt::AlignCenter);
    }
    if(CurrentValue>(totaltime/6)&&CurrentValue<=(totaltime/2)){
        ui->progressBar_time->setStyleSheet("QProgressBar::chunk { background-color: rgb(255, 255, 0) }");
        ui->progressBar_time->setAlignment(Qt::AlignCenter);
    }
    if(CurrentValue<=(totaltime/6)){
        ui->progressBar_time->setStyleSheet("QProgressBar::chunk { background-color: rgb(255, 0, 0) }");
        ui->progressBar_time->setAlignment(Qt::AlignCenter);
    }
    if(CurrentValue>4)
        mus->Music_last_4sOFF();
    if(CurrentValue==4)
        mus->Music_last_4sON();
    if (CurrentValue<=0){
        Game_over();
    }
    ui->progressBar_time->setValue(CurrentValue);
}

//cgamelog界面显示时游戏开始
void CGameDlg::Game_start(){
    timer->start(1000); //每一秒更新一次timerbar
    gemtype="gem"; //默认宝石类型

    gamelogic->setgame_running(true); //初始设置游戏处于运行状态
    g_spc=5;
    gamelogic->BuildMap(g_spc);  //初始化游戏地图
    g_rank.nGrade=0;
    string_grade="";
    this->repaint();

    ui->progressBar_time->setMaximum(totaltime);
    ui->progressBar_time->setValue(totaltime);
    ui->progressBar_time->setStyleSheet("QProgressBar::chunk { background-color: rgb(0, 255, 0) }");
    ui->progressBar_time->setAlignment(Qt::AlignCenter);
    ui->pushButton_continue->hide(); //初始时"继续游戏"按钮不可见
    ui->pushButton_restart->hide();  //初始时"重新开始"按钮不可见
    ui->pushButton_stop->show(); //初始时"暂停游戏"按钮可见
    ui->pushButton_continue->setEnabled(false); //初始时"继续游戏"按钮不可用
    ui->pushButton_restart->setEnabled(false); //初始时"重新开始"按钮不可用
    ui->pushButton_stop->setEnabled(true); //初始时"暂停游戏"按钮可用
    label_image->hide(); //初始时暂停游戏以及结束的图片都隐藏

    props=false;
    cross=false;
    boom=false;
    color=false;
    g_props_boom=1;
    g_props_color=1;
    g_props_cross=1;
    ui->label_hammer->setText("0");
    ui->label_boom->setText(QString::number(g_props_boom));
    ui->label_color->setText(QString::number(g_props_color));
    ui->label_cross->setText(QString::number(g_props_cross));
}

//时间耗尽，游戏结束
void CGameDlg::Game_over(bool saveRank){
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

    if(saveRank)
        ranklogic->insertIndex(ranklogic->getIndex());
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
    mus->gameSound->setVolume(0);

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
    mus->gameSound->setVolume(10);

}

void CGameDlg::on_pushButton_restart_clicked()
{
    timer->start();
    label_image->hide();
    ui->progressBar_time->setMaximum(totaltime);
    ui->progressBar_time->setValue(totaltime);
    ui->progressBar_time->setStyleSheet("QProgressBar::chunk { background-color: rgb(0, 255, 0) }");
    ui->progressBar_time->setAlignment(Qt::AlignCenter);

    //重新生成地图，待完成
    g_spc=5;
    gamelogic->BuildMap(g_spc);
    gamelogic->setgame_running(true);
    g_rank.nGrade=0;
    string_grade="";
    this->repaint();

    ui->pushButton_restart->hide();
    ui->pushButton_restart->setEnabled(false);
    ui->pushButton_stop->show();
    ui->pushButton_stop->setEnabled(true);

    props=false;
    cross=false;
    boom=false;
    color=false;
    g_props_boom=1;
    g_props_color=1;
    g_props_cross=1;
    ui->label_hammer->setText("0");
    ui->label_boom->setText(QString::number(g_props_boom));
    ui->label_color->setText(QString::number(g_props_color));
    ui->label_cross->setText(QString::number(g_props_cross));

}

//音乐开
void CGameDlg::on_pushButton_clicked()
{
    music = 1;
    mus->gameSound->setVolume(10);
}

//音乐关
void CGameDlg::on_pushButton_2_clicked()
{
    music = 0;
    mus->gameSound->setVolume(0);
}




//************* 道具部分 ***************

//消除任意一个宝石
void CGameDlg::on_pushButton_hammer_clicked()
{

}

//交换地图中任意两个宝石
void CGameDlg::on_pushButton_exchange_clicked()
{
    if(g_props_cross!=0){
        props=true;
        cross=true;
    }
}

//消除地图中任意一行（还是列，暂时不确定）的宝石
void CGameDlg::on_pushButton_connection_clicked()
{
    if(g_props_color!=0){
        props=true;
        color=true;
    }
}

//产生爆炸，消除一定范围（数量待定）的宝石
void CGameDlg::on_pushButton_bomb_clicked()
{
    if(g_props_boom){
        props=true;
        boom=true;
    }
}
