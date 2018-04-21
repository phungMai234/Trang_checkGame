
#include <iostream>
#include"console.h"
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include<stdint-gcc.h>
#include"IstructKhoiGach.h"
#include"ItaoKhoiGach.h"
#include"IdiChuyenKhoiGach.h"




int Board[MaxI][MaxJ];

using namespace std;



void VeKhoiGach(KhoiGach* pkhoigach)
{
    int i;
    int j;
    for(i = 0;i < pkhoigach->Row; i++)
        for(j = 0;j < pkhoigach->Col; j++)
            if(pkhoigach->arr[i][j] == 1 && (pkhoigach->iBoard + i )> 3) // arr k hieu
            {
                TextColor(13);
                gotoXY(LEFT + pkhoigach->jBoard + j + 1, TOP + pkhoigach->iBoard + i - 3);
                cout << char(2); // nho cout ra
            }
}

void XoaKhoiGach(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1 && (pkhoigach->iBoard + i) > 3)
            {
                TextColor(0);
                gotoXY(LEFT + pkhoigach->jBoard + j + 1, TOP + pkhoigach->iBoard + i - 3);
                cout <<" ";
            }
        }
    }
}
// ham kiem tra khoi gach co nam trong bang hay k


//--------------------------------------------------------------------------------------------------
// hien thi thong tin tro choi
struct INFO
{
    int score;
    int level;
    float speed;
};

void InitGame(INFO *info)
{
    info->level=1;
    info->score=0;
    info->speed=0.7;
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
void VeBangDiem(INFO info)
{
    TextColor(15);
    gotoXY(LEFT+MaxJ+2,10);
    cout << "  SCORE: " << info.score;
    gotoXY(LEFT+MaxJ+2,11);
    cout << "  LEVEL: " << info.level;
    gotoXY(LEFT+MaxJ+2,12);
    cout << "  SPEED: " << info.speed;
}
//-------------------------------------------------

void HuyKhoiGach(KhoiGach* pkhoigach)
{
    int i;
    //Huy bo nho cua ma tran trang thai arr.
    for(i=0;i<pkhoigach->Row;i++)
        delete(pkhoigach->arr[i]);
    delete(pkhoigach->arr);
    /////////////////////////////////////////////////////////
    //Sau do moi free(pkhoigach)
    delete(pkhoigach);
    pkhoigach=NULL;
}
// ham xuat hien khoi gahc tiep theo
//--------------------------------------------------------------------
void Ve_Next(int ID)
{
    KhoiGach *pnext=TaoKhoiGach(ID);
    int iRoot=LEFT+MaxJ + 5;
    int jRoot=TOP;
    for(int i=0;i<pnext->Row;i++)
    {
        for (int j=0;j<pnext->Col;j++)
        {
            if(pnext->arr[i][j]==1)
            {
                TextColor(15);
                gotoXY(iRoot+j,jRoot+i);
                cout << char(2);
            }
        }

    }
    HuyKhoiGach(pnext);
}
void Xoa_Next()
{
    int iRoot=LEFT+MaxJ+5;
    int jRoot=TOP;
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {

                TextColor(0);
                gotoXY(iRoot+j,jRoot+i);
                cout << " "; // chú ý in ra dấu cách
        }

    }
}

// giai phong bo nhp

//---------------------------------------------------------------------------------------------
void GanGiaTri(KhoiGach* pkhoigach)
{
    for(int i=0;i<pkhoigach->Row;i++)
        for(int j=0;j<pkhoigach->Col;j++)
            if(pkhoigach->arr[i][j]==1)
            {
                Board[pkhoigach->iBoard+i][pkhoigach->jBoard+j]=1;
            }
}

void DisplayBoard()
{
    int i,j;
    for(i=0;i<MaxI;i++)
        for(j=0;j<MaxJ;j++)
        {
            if(Board[i][j]==1&&i>=4)
            {
                gotoXY(j+LEFT+1,i+TOP+1-4);TextColor(14);cout << char(2);
            }
            if(Board[i][j]==0&&i>=4)
            {
                TextColor(0);gotoXY(j+LEFT+1,i+TOP+1-4);cout << " ";
            }
        }
}

void CapNhatLaiToaDo(int hang)
{
    int i,j;
    for(i=hang;i>0;i--)
        for(j=0;j<MaxJ;j++)
        {
            Board[i][j]=Board[i-1][j];
        }
}
int KiemTra(KhoiGach *pkhoigach,INFO *infogame) //-1 : gameover 0: win
{
        int i,j,count;
        i=pkhoigach->Row - 1;
        if(pkhoigach->iBoard<=3) return -1;//Gameover
        if(infogame->score>=300) return 0;//Win
        do
        {
            count=0;
            for(j=0;j<MaxJ;j++)
            {
                if(Board[pkhoigach->iBoard+i][j]==1)    count++;
            }
            if(count==MaxJ)
            {
                CapNhat(infogame,20);
                CapNhatLaiToaDo(pkhoigach->iBoard+i);
                DisplayBoard();
            }
            else
            {
                i=i-1;
            }
        }while(i>=0);
        return 1;
}


void DrawBoard()
{
    int i,j;
    for(i=LEFT;i<=LEFT+10+1;i++)
        for(j=TOP;j<=TOP+18+1;j++)
        {
            if((j==TOP||j==TOP+18+1)&&i>LEFT&&i<LEFT+10+1)
            {
                gotoXY(i,j);TextColor(7);
                cout << char(205);
            }
            if((i==LEFT||i==LEFT+10+1)&&j>TOP&&j<TOP+18+1)
            {
                gotoXY(i,j);TextColor(7);
                cout << char(186);
            }
        }
        gotoXY(LEFT,TOP);TextColor(10);cout << char(219);
        gotoXY(LEFT+10+1,TOP);TextColor(10);cout << char(219);
        gotoXY(LEFT,TOP+18+1);TextColor(10);cout << char(219);
        gotoXY(LEFT+10+1,TOP+18+1);TextColor(10);cout << char(219);

}
bool help()
{
    char choice;
    cout << "------------------Guide to Play Tetris Game----------------\n"
            "- Tetris Game is a puzzle with the shapes each consisting -\n"
            "- of several squares, that are falling down the well.     -\n"
            "- When playing a tetris game, one turns them or moves left-\n"
            "- and right, trying to arrange the shapes in a line.      -\n"
            "- When a line of squares makes a line from edge to edge,  -\n"
            "- it disappears and all the pieces move down by a square. -\n"
            "- When the well is filled up, the player lose.            -\n";

    cout << "Do you want to back Main menu? (Y/N) \n";

    choice = _getch();
    if(choice == 'N' || choice == 'n')
        return false;
    return true;
}
bool credit()
{
    char choice;
    cout << "--------Credit Game Tetris-------\n"
            "-- Author: Phung Thi Tuyet Mai --\n"
            "-- Number: 17020875            --\n"
            "-- Class : K62IE3              --\n"
            "---------------------------------\n";
    cout << "Do you want to back Main menu? (Y/N) \n";

    choice = _getch();
    if(choice == 'N' || choice == 'n')
        return false;
    return true;
}
void dieuKhienChinh()
{
    clrscr();
    int IDKhoiTiepTheo;
    clock_t Start, End;
    char key;

    INFO info;
    KhoiGach *currKhoi;
    currKhoi = TaoKhoiGach(Loai());
    IDKhoiTiepTheo = Loai();
    DrawBoard();
    InitGame(&info);
    do
    {
        VeBangDiem(info);
        VeKhoiGach(currKhoi);
        Xoa_Next();
        Ve_Next(IDKhoiTiepTheo);
        Start = clock();
        do
        {
//            if(_kbhit())
//            {
//
//                XoaKhoiGach(currKhoi);
//                if(GetAsyncKeyState(VK_LEFT))
//                    SangTrai(currKhoi);
//                if(GetAsyncKeyState(VK_RIGHT))
//                    SangPhai(currKhoi);
//                if(GetAsyncKeyState(VK_DOWN))
//                    RoiXuong(currKhoi);
//                if(GetAsyncKeyState(VK_UP))
//                    XoayKhoiGach(currKhoi);
//                VeKhoiGach(currKhoi);
//            }
            if(_kbhit())
            {

                key = _getch();
                XoaKhoiGach(currKhoi);
                if(key == 'a' || key == 'A')
                    SangTrai(currKhoi);
                if(key == 'd' || key == 'D')
                    SangPhai(currKhoi);
                if(GetAsyncKeyState(VK_UP))
                    RoiXuong(currKhoi);
                if(key == 'w' || key == 'W')
                    XoayKhoiGach(currKhoi);
                VeKhoiGach(currKhoi);
            }
//            system("pause");
            End = clock();
        }while(float(End - Start) / CLK_TCK < info.speed);
        XoaKhoiGach(currKhoi);
        if(RoiXuong(currKhoi) == 0)
        {
            GanGiaTri(currKhoi);

            int ketqua = KiemTra(currKhoi, &info);
            if(ketqua == -1 || ketqua == 0)
                break;

            HuyKhoiGach(currKhoi); // giai phong bôj nhớ

            currKhoi = TaoKhoiGach(IDKhoiTiepTheo);
            IDKhoiTiepTheo = Loai();
        }
        DisplayBoard(); // ve khoi đẫ rơi cuống cuốibảng

    }while(1);
    clrscr();
    TextColor(15); // khai bao duoi de lam j
    gotoXY(35,10);
    cout << "GAME OVER\n";

    cout << "YOU GOT: " << info.score << endl;

    cout << "End Game.Press anykey to back to Main Menu.";
    _getch(); // cái n� y để l� m j
}

int main() /* chay chưa het game đã dừng*/
{
    char choice;

    do
    {
        /*Draw a main menu */
        cout << "--------------GAME TETRIS-------------" << endl;
        cout << "**************MAIN MENU**************" << endl;
        cout << "(1) - New Game" <<  endl;
        cout << "(2) - Help" << endl;
        cout << "(3) - Credit" << endl;
        cout << "(4) - Quit Game" << endl;
        cout << "--------------------------------------" << endl;
        /*Get a character from keyvoard*/
        choice = _getch();
        /*choose a function to be exercuted*/

        if(choice == '1')
        {
            dieuKhienChinh();
        }
        if(choice == '2')
        {
            clrscr();
            if(!help())
                break;
        }
        if(choice == '3')
        {
            clrscr();
            if(!credit())
                break;
        }
        if(choice == '4')
        {
            break;
        }
        clrscr();
    }while(1);


    return 0;
//    int ID = Loai();
//    KhoiGach* currKhoi;
//
//    currKhoi = TaoKhoiGach(ID);
//    VeKhoiGach(currKhoi);
//    while(1)
//        {
//            if(_kbhit())
//            {
//                clrscr();
//                DrawBoard();
//                char key = _getch();
//                if(key == 'a' || key == 'A')
//                    SangTrai(currKhoi);
//                if(key == 'd' || key == 'D')
//                    SangPhai(currKhoi);
//                if(key == 's' || key == 'S')
//                    RoiXuong(currKhoi);
//                if(key == 'w' || key == 'W')
//                    XoayKhoiGach(currKhoi);
//                VeKhoiGach(currKhoi);
//            }
//            else
//            {   clrscr();
//                RoiXuong(currKhoi);
//                VeKhoiGach(currKhoi);
//
//            }
//            Sleep(500);
//        }


}
