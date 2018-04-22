
#include<iostream>
#include"I_INFO_game.h"
#include"Istruct_INFO.h"

void InitGame(INFO *info)
{
    info->level=1;
    info->score=0;
    info->speed=0.6;
}

int CapNhat(INFO *info, int score)
{
    info->score+=score;
    if(info->score>=200&&info->level<2)
    {
        info->level++;
        info->speed-=0.1;
    }
    return 0; //Chua win game.
}
