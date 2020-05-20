#include "crankdao.h"

CRankDao::CRankDao()
{
    for(int i = 0; i < 10; i++)
        ranks[i] = nullptr;
}

void CRankDao::getRank()
{
    string str;
    int time;
    int grade;
    ifstream infile("rank.ini");
    infile >> str;
    for(totalNumber = 0; !str.empty(); totalNumber++)
    {
        ranks[totalNumber] = new RANKINFOR();
        memcpy((*ranks[totalNumber]).strName, str.c_str(), 50);
        infile >> time;
        (*ranks[totalNumber]).nTime = time;
        infile >> grade;
        (*ranks[totalNumber]).nGrade = grade;
        infile >> str;
    }
    infile.close();
}

void CRankDao::saveRank()
{
    ofstream outfile("rank.ini");
    for(int i = 0; ranks[i] != nullptr && i < 10; i++)
    {
        outfile << (*ranks[i]).strName << " " << (*ranks[i]).nTime << " " << (*ranks[i]).nGrade << endl;
    }
    outfile.close();
}
