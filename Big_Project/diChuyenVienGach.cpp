#include"IdiChuyenVienGach.h"
#include"IstructKhoiGach.h"

bool Inside(int i, int j)
{
    if((i >= 0 && i < MaxI) && (j >= 0 && j < MaxJ))
        return true;
    else
        return false;
}

// ham di chuyen mot khoi gach sang trai, phai, xuong

bool Left(int i, int j)
{
    if(j > 0 && Inside(i, j)==true && Board[i][j - 1] == 0)
        return true;
    return false;
}
bool Right(int i, int j)
{
    if((j < MaxJ - 1) && Inside(i, j)==true && Board[i][j + 1] == 0)
        return true;
    return false;
}
bool Down(int i, int j)
{
    if((i < MaxI - 1) && Inside(i, j)==true && Board[i + 1][j] == 0)
        return true;
    return false;
}
