#ifndef CRANKDAO_H
#define CRANKDAO_H

#include "Global.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QFile>
#include <QTextStream>

using namespace std;

class CRankDao
{
public:
    CRankDao();

    void getRank();

    void saveRank();

public:
    RANKINFOR *ranks[10];
    int totalNumber = 0;
};

#endif // CRANKDAO_H
