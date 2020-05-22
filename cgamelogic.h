#ifndef CGAMELOGIC_H
#define CGAMELOGIC_H

class CGameLogic
{
public:
    CGameLogic();

private:
    int species;//宝石种类数
    int m_aMap[8][8];//0代表空，1~n代表第n种宝石

    void BuildMap();//生成不三连的图形
    bool swap(int a, int b, int m, int n);//交换（不相邻或无法消子，返回false）需要调用eliminate；也可以不这样写
    bool eliminate();//消子
    void down();//下移
    void produce();//产生新子
    //这里有计时函数
    //暂停函数
    void newGrade();//不太清楚怎么做
    bool isWin();//胜负判断？或者升级？
    void hint();//提示（需要扣分）
    //应该没了，大家有需要再补充

};

#endif // CGAMELOGIC_H
