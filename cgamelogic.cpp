#include "cgamelogic.h"

CGameLogic::CGameLogic()
{

}


//生成地图并且任意相邻的三个宝石不同，将8*8随机数矩阵传递给m_aMap二维数组中
void CGameLogic::BuildMap(){
    int gemnum;//宝石编号，从1-8
    srand((int)time(0));

    //初始生成8*8的数字矩阵
    for(int n=0;n<maprownum;n++){
        for(int m =0;m<mapcolnum;m++){
            gemnum = rand()%8+1; //生成1-8的随机数
            m_aMap[n][m]=gemnum;
        }
    }

    while(checkmap()){
        //判断横向是否有相邻的三个宝石相同
        for(int j=0;j<maprownum;j++){
            for(int i=0;i<maprownum-3+1;i++){
                int check[3]; //用于检查宝石是否相同
                for(int n=0;n<3;n++){
                    check[n]=m_aMap[j][i+n];
                }
                if(check[0]==check[1]&&check[1]==check[2]){
                    while(check[1]==check[0]){
                        check[1]=rand()%8+1;
                        m_aMap[j][i+1]=check[1];
                    }
                }
            }
        }

        //判断纵向是否有相邻的三个宝石相同
        for(int j=0;j<mapcolnum;j++){
            for(int i=0;i<maprownum-3+1;i++){
                int check[3]; //用于检查宝石是否相同
                for(int n=0;n<3;n++){
                    check[n]=m_aMap[i+n][j];
                }
                if(check[0]==check[1]&&check[1]==check[2]){
                    while(check[1]==check[0]){
                        check[1]=rand()%8+1;
                        m_aMap[i+1][j]=check[1];
                    }
                }
            }
        }
    }

    qDebug()<<"\n====这是生成的宝石地图（1-8表示宝石号码），若要删除这个显示，在cgamelogic.cpp下的BuildMap()函数末尾=====";
    for(int n=0;n<maprownum;n++){
        QString temp="";
        for(int m =0;m<mapcolnum;m++){
            temp+=QString::number(m_aMap[n][m]);
        }
        qDebug()<<temp;
    }
}


//只是为了再次判断地图中是否有相邻的三个宝石相同，只用于BuildMap()中引用,写其他代码时可忽略此函数。
bool CGameLogic::checkmap(){
    //判断横向是否有相邻的三个宝石相同
    for(int j=0;j<maprownum;j++){
        for(int i=0;i<maprownum-3+1;i++){
            int check[3]; //用于检查宝石是否相同
            for(int n=0;n<3;n++){
                check[n]=m_aMap[j][i+n];
            }
            if(check[0]==check[1]&&check[1]==check[2]){
                return true;
            }
        }
    }

    //判断纵向是否有相邻的三个宝石相同
    for(int j=0;j<mapcolnum;j++){
        for(int i=0;i<maprownum-3+1;i++){
            int check[3]; //用于检查宝石是否相同
            for(int n=0;n<3;n++){
                check[n]=m_aMap[i+n][j];
            }
            if(check[0]==check[1]&&check[1]==check[2]){
                return true;
            }
        }
    }
    return false;
}


void CGameLogic::setgame_running(bool game_running){
    this->game_running=game_running;
}
