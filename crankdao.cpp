#include "crankdao.h"
#include <direct.h>

CRankDao::CRankDao()
{

}

int CRankDao::getRank()
{
    QString str;
    int time = 0;
    int grade = 0;
    QFile file(QDir::currentPath() + "/rank.ini");
    if(!file.exists())
    {
        file.open(QIODevice::WriteOnly);
        file.close();
    }
    file.open(QIODevice::ReadOnly);
    QTextStream instream(&file);
    instream >> str;
    int i = 0;
    for(; str != ""; i++)
    {
        ranks[i] = new RANKINFOR();
        memcpy(ranks[i]->strName, str.toStdString().c_str(), 50);
        instream >> time;
        ranks[i]->nTime = time;
        instream >> grade;
        ranks[i]->nGrade = grade;
        instream >> str;
    }
    file.close();
    return i;
}

void CRankDao::saveRank()
{
    QFile file(QDir::currentPath() + "/rank.ini");
    file.open(QIODevice::WriteOnly);
    QTextStream outstream(&file);
    for(int i = 0; ranks[i] != nullptr && i < 10; i++)
    {
        outstream << ranks[i]->strName << " " << ranks[i]->nTime << " " << ranks[i]->nGrade << endl;
    }
    file.close();
}
