#ifndef ISTRUCTKHOIGACH_H_INCLUDED
#define ISTRUCTKHOIGACH_H_INCLUDED

#define LEFT 4
#define TOP 4

#define MaxI 22
#define MaxJ 10
struct KhoiGach
{
    int **arr; // la cai j
    int Row, Col;
    int iBoard, jBoard; // jBoard chỉ h� ng, iBoard chỉ cột
};

#endif // ISTRUCTKHOIGACH_H_INCLUDED
