#include "cgamelogic.h"

CGameLogic::CGameLogic()
{

}


//生成地图并且任意相邻的三个宝石不同，将8*8随机数矩阵传递给m_aMap二维数组中
void CGameLogic::BuildMap(int gemspecies){
    int gemnum;//宝石编号，从1-8
    srand((int)time(0));

    //初始生成8*8的数字矩阵
    for(int n=0;n<maprownum;n++){
        for(int m =0;m<mapcolnum;m++){
            gemnum = rand()%gemspecies+1; //生成1-gemspecies的随机数
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
                        check[1]=rand()%gemspecies+1;
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
                        check[1]=rand()%gemspecies+1;
                        m_aMap[i+1][j]=check[1];
                    }
                }
            }
        }
    }

    qDebug()<<"\n====这是生成的宝石地图（1-n表示宝石号码），若要删除这个显示，在cgamelogic.cpp下的BuildMap()函数末尾=====";
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

bool CGameLogic::eliminate(bool noChange)
{
    if(!game_running)
        return false;
    bool isChange = false;
    int current = 0;
    int temp_aMap[8][8];
    memcpy(temp_aMap, m_aMap, sizeof(m_aMap));
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 6; i++)
        {
            current = m_aMap[i][j];
            if(current == m_aMap[i + 1][j] && current == m_aMap[i + 2][j])
            {
                temp_aMap[i][j] = 0;
                temp_aMap[i + 1][j] = 0;
                temp_aMap[i + 2][j] = 0;
                isChange = true;
            }
        }
    }
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 6; i++)
        {
            current = m_aMap[j][i];
            if(current == m_aMap[j][i + 1] && current == m_aMap[j][i + 2])
            {
                temp_aMap[j][i] = 0;
                temp_aMap[j][i + 1] = 0;
                temp_aMap[j][i + 2] = 0;
                isChange = true;
            }
        }
    }
    if(noChange)
        return isChange;
    memcpy(m_aMap, temp_aMap, sizeof(m_aMap));
    return isChange;
}

void CGameLogic::down()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 7; j >= 0; j--)
        {
            if(m_aMap[j][i] == 0)
            {
                for(int k = j; k > 0; k--)
                {
                    m_aMap[k][i] = m_aMap[k - 1][i];
                }
                m_aMap[0][i] = 0;
            }
        }
    }
    //下移完毕
    srand((int)time(0));
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(m_aMap[i][j] == 0)
                m_aMap[i][j] = rand()%5 + 1;
        }
    }
}

void CGameLogic::setgame_running(bool game_running){
    this->game_running=game_running;
}

bool CGameLogic::swap(int a,int b,int m,int n){//传入坐标(a,b)和(m,n)
        if(game_running){
            if(a==m){//同行？
                if(((b-n)==1)or((b-n)==-1)){//相邻？
                    int mid=m_aMap[a][b];
                    m_aMap[a][b]=m_aMap[m][n];
                    m_aMap[m][n]=mid;
                    if(checkmap()){
                        return true;
                    }else{
                        mid=m_aMap[a][b];
                        m_aMap[a][b]=m_aMap[m][n];
                        m_aMap[m][n]=mid;
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                if(b==n){//同列？
                    if(((a-m)==1)or((a-m)==-1)){//相邻？
                        int mid=m_aMap[a][b];
                        m_aMap[a][b]=m_aMap[m][n];
                        m_aMap[m][n]=mid;
                        if(checkmap()){
                            return true;
                        }else{
                            mid=m_aMap[a][b];
                            m_aMap[a][b]=m_aMap[m][n];
                            m_aMap[m][n]=mid;
                            return false;
                        }
                        return true;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }else{
            return false;
        }
}

bool CGameLogic::hint(){
    int map[8][8];
    int i,j;
    int mid;//交换过渡
    int tap = 0;//判断找到没有

    for(i = 0; i < 8; i++){
            for(j = 0; j < 8; j++){
                map[i][j]=m_aMap[i][j];
            }
        }

    for(i = 0; i < 7; i++){
        for(j = 0; j < 8; j++){
            mid = map[i][j];
            map[i][j] = map[i+1][j];
            map[i+1][j] = mid;

                if(map[i+1][j]==map[i+2][j]&&map[i+2][j]==map[i+3][j]){
                    if(i<=4){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i+1;
                        point[1][1] = j;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i][j]==map[i][j+1]&&map[i][j+1]==map[i][j+2]){
                    if(j<=5){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i+1;
                        point[1][1] = j;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i+1][j]==map[i+1][j+1]&&map[i+1][j+1]==map[i+1][j+2]){
                    if(j<=4){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i+1;
                        point[1][1] = j;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i][j]==map[i-1][j]&&map[i-1][j]==map[i-2][j]){
                    if(i>=2){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i+1;
                        point[1][1] = j;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i][j]==map[i][j-1]&&map[i][j-1]==map[i][j+1]){
                    if(j>0&&j<7){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i+1;
                        point[1][1] = j;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i][j]==map[i][j-1]&&map[i][j-1]==map[i][j-2]){
                    if(j>=2){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i+1;
                        point[1][1] = j;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i+1][j]==map[i+1][j-1]&&map[i+1][j-1]==map[i+1][j-2]){
                    if(j>=2){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i+1;
                        point[1][1] = j;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i+1][j]==map[i+1][j-1]&&map[i+1][j-1]==map[i][j+1]){
                    if(j>0&&j<7){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i+1;
                        point[1][1] = j;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else{
                    mid = map[i][j];
                    map[i][j] = map[i+1][j];
                    map[i+1][j] = mid;
                    tap = 0;
                }
        }

    }

    if(tap == 0){
        for(i = 0; i < 8; i++){
            for(j = 0; j < 7; j++){
                mid = map[i][j];
                map[i][j] = map[i][j+1];
                map[i][j+1] = mid;

                if(map[i][j]==map[i+1][j]&&map[i+1][j]==map[i+2][j]){
                    if(i<=5){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i;
                        point[1][1] = j+1;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i][j]==map[i][j-1]&&map[i][j-1]==map[i][j-2]){
                    if(j>=2){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i;
                        point[1][1] = j+1;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i+1][j]==map[i][j]&&map[i][j]==map[i-1][j]){
                    if(i>0&&i<7){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i;
                        point[1][1] = j+1;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i][j]==map[i-1][j]&&map[i-1][j]==map[i-2][j]){
                    if(i>=2){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i;
                        point[1][1] = j+1;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i][j+1]==map[i-1][j+1]&&map[i-1][j+1]==map[i+1][j+1]){
                    if(i>0&&i<7){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i;
                        point[1][1] = j+1;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i][j+1]==map[i+1][j+1]&&map[i+1][j+1]==map[i+2][j+1]){
                    if(i<=5){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i;
                        point[1][1] = j+1;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i][j+1]==map[i][j+2]&&map[i][j+2]==map[i][j+3]){
                    if(j<=4){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i;
                        point[1][1] = j+1;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else if(map[i][j+1]==map[i-1][j+1]&&map[i-1][j+1]==map[i-2][j+1]){
                    if(i>=2){
                        point[0][0] = i;
                        point[0][1] = j;
                        point[1][0] = i;
                        point[1][1] = j+1;
                        i=8;
                        j=8;
                        tap = 1;
                    }
                }else{
                    mid = map[i][j];
                    map[i][j] = map[i+1][j];
                    map[i+1][j] = mid;
                    tap = 0;
                }
            }
        }
    }
    return tap;
}
