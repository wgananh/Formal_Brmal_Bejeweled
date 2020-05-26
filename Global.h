#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct RANKINFORMATION
{
    char strName[50];
    int nTime;
    int nGrade;
    int nRank;
} RANKINFOR;

extern RANKINFOR g_rank;

typedef struct PICTUREELEMENT
{
    int nRow;
    int nCol;
    int nPicNum;
} PICELEM;

extern PICELEM m_aMap;

#endif // GLOBAL_H
