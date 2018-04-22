
#include"Imenu.h"
#include<iostream> // cout


#include<conio.h> // thu vien cua _getch


using namespace std; // cout

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
