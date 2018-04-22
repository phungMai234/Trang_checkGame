#ifndef TAOKHOIGACH_CPP_INCLUDED
#define TAOKHOIGACH_CPP_INCLUDED
#include"ItaoKhoiGach.h"
#include<ctime>
#include<conio.h>
#include<windows.h>

KhoiGach *TaoKhoiGach(int ID)
{
    KhoiGach *pkhoigach = new KhoiGach;
    switch(ID)
    {
        case 15: // hình chữ I
            pkhoigach->Row=4;
            pkhoigach->Col = 1;
            pkhoigach->iBoard=0;
            pkhoigach->jBoard=5;
            break;
        case 31: // hinh vuông
            pkhoigach->Row=pkhoigach->Col=2;
            pkhoigach->iBoard=2;
            pkhoigach->jBoard=5;
            break;
        default: // hình T,L,Z
            pkhoigach->Row=2;
            pkhoigach->Col=3;
            pkhoigach->iBoard=2;
            pkhoigach->jBoard=5;
            break;
    }
    pkhoigach->arr = new int*;
    for(int i = 0; i < pkhoigach->Row; i++)
    {
        pkhoigach->arr[i] = new int;
    }
    for(int k = 0; k < pkhoigach->Col * pkhoigach->Row; k++)
    {
        pkhoigach->arr[k / pkhoigach->Col][k % pkhoigach->Col] = (ID >> (pkhoigach->Col * pkhoigach->Row - 1 - k)) & 1;
    }
    return pkhoigach;
}
int Loai()
{
    srand(time(NULL));
    int x=rand()%7;
    switch(x)
    {
        case 0:
            return 15;
            break;
        case 1:
            return 31;
            break;
        case 2:
            return 51;
            break;
        case 3:
            return 30;
            break;
        case 4:
            return 58;
            break;
        case 5:
            return 57;
            break;
        case 6:
            return 60;
            break;
    }
}



#endif // TAOKHOIGACH_CPP_INCLUDED
