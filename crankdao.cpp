#include "crankdao.h"
#include <direct.h>

CRankDao::CRankDao()
{
    for(int i = 0; i < 10; i++)
        ranks[i] = nullptr;
}

void CRankDao::getRank()
{
    QString str;
    int time = 0;
    int grade = 0;
    QFile file(":/rank/rank.ini");
    file.open(QIODevice::ReadOnly);
    QTextStream instream(&file);
    instream >> str;
    for(totalNumber = 0; str != ""; totalNumber++)
    {
        ranks[totalNumber] = new RANKINFOR();
        memcpy((*ranks[totalNumber]).strName, str.toStdString().c_str(), 50);
        instream >> time;
        (*ranks[totalNumber]).nTime = time;
        instream >> grade;
        (*ranks[totalNumber]).nGrade = grade;
        instream >> str;
    }
    file.close();
}

void CRankDao::saveRank()
{
    QFile file(":/rank/rank.ini");
    file.open(QIODevice::WriteOnly);
    QTextStream outstream(&file);
    for(int i = 0; ranks[i] != nullptr && i < 10; i++)
    {
        outstream << (*ranks[i]).strName << " " << (*ranks[i]).nTime << " " << (*ranks[i]).nGrade << endl;
    }
    file.close();
}
