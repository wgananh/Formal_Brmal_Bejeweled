#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct RANKINFORMATION
{
    char strName[50];
    int nTime;
    int nGrade;
    int nRank;
} RANKINFOR;

typedef struct PICTUREELEMENT
{
    int nRow;
    int nCol;
    int nPicNum;
} PICELEM;

#endif // GLOBAL_H
