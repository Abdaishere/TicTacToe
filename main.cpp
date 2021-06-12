#include <iostream>
#include <stdlib.h>
using namespace std;

char board[3][4] = {
    //012
    "...",  //0
    "...",  //1
    "...",  //2
};
int x, y, mode;
bool won;
bool checkboard()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != '.')
            return true;
        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != '.')
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != '.')
        return true;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != '.')
        return true;

    return false;
}
void computerplay(int& x, int& y, int i)
{
    switch (i)
    {
    case 0:
        y = 2; x = 0;
        break;
    case 2:
        if (board[2][2] == '.') { y = 2; x = 2; }
        else if (board[1][1] == '.') { y = 1; x = 1; }
        break;
    case 4:
        if (board[0][0] == '.') { x = 0; y = 0; }
        else if (board[0][2] == '.') { x = 2; y = 0; }
        break;
    }
    if (i >= 4)
    {
        for (int i = 0; i < 3; i++)
        {
            if ((board[i][0] == 'X' && board[i][1] == 'X') || (board[i][0] == 'X' && board[i][2] == 'X') || (board[i][1] == 'X' && board[i][2] == 'X'))
            {
                if (board[i][2] == '.' && board[i][0] == 'X' && board[i][1] == 'X') { x = 2; y = i; return; }
                if (board[i][1] == '.' && board[i][0] == 'X' && board[i][2] == 'X') { x = 1; y = i; return; }
                if (board[i][0] == '.' && board[i][1] == 'X' && board[i][2] == 'X') { x = 0; y = i; return; }
            }
            else if ((board[0][i] == 'X' && board[1][i] == 'X') || (board[0][i] == 'X' && board[2][i] == 'X') || (board[1][i] == 'X' && board[2][i] == 'X'))
            {
                if (board[2][i] == '.' && board[0][i] == 'X' && board[1][i] == 'X') { x = i; y = 2; return; }
                if (board[1][i] == '.' && board[0][i] == 'X' && board[2][i] == 'X') { x = i; y = 1; return; }
                if (board[0][i] == '.' && board[1][i] == 'X' && board[2][i] == 'X') { x = i; y = 0; return; }
            }
        }
        if ((board[0][0] == 'X' && board[1][1] == 'X') || (board[0][0] == 'X' && board[2][2] == 'X') || (board[1][1] == 'X' && board[2][2] == 'X'))
        {
            if (board[2][2] == '.' && board[0][0] == 'X' && board[1][1] == 'X') { x = 2; y = 2; return; }
            if (board[1][1] == '.' && board[0][0] == 'X' && board[2][2] == 'X') { x = 1; y = 1; return; }
            if (board[0][0] == '.' && board[1][1] == 'X' && board[2][2] == 'X') { x = 0; y = 0; return; }
        }
        if ((board[0][2] == 'X' && board[1][1] == 'X') || (board[0][2] == 'X' && board[2][0] == 'X') || (board[1][1] == 'X' && board[2][0] == 'X'))
        {
            if (board[2][0] == '.' && board[0][2] == 'X' && board[1][1] == 'X') { x = 0; y = 2; return; }
            if (board[1][1] == '.' && board[0][2] == 'X' && board[2][0] == 'X') { x = 1; y = 1; return; }
            if (board[0][2] == '.' && board[1][1] == 'X' && board[2][0] == 'X') { x = 2; y = 0; return; }
        }
        for (int i = 0; i < 3; i++)
        {
            if ((board[i][0] == 'O' && board[i][1] == 'O') || (board[i][0] == 'O' && board[i][2] == 'O') || (board[i][1] == 'O' && board[i][2] == 'O'))
            {
                if (board[i][2] == '.' && board[i][0] == 'O' && board[i][1] == 'O') { x = 2; y = i; return; }
                if (board[i][1] == '.' && board[i][0] == 'O' && board[i][2] == 'O') { x = 1; y = i; return; }
                if (board[i][0] == '.' && board[i][1] == 'O' && board[i][2] == 'O') { x = 0; y = i; return; }
            }
            else if ((board[0][i] == 'O' && board[1][i] == 'O') || (board[0][i] == 'O' && board[2][i] == 'O') || (board[1][i] == 'O' && board[2][i] == 'O'))
            {
                if (board[2][i] == '.' && board[0][i] == 'O' && board[1][i] == 'O') { x = i; y = 2; return; }
                if (board[1][i] == '.' && board[0][i] == 'O' && board[2][i] == 'O') { x = i; y = 1; return; }
                if (board[0][i] == '.' && board[1][i] == 'O' && board[2][i] == 'O') { x = i; y = 0; return; }
            }
        }
        if ((board[0][0] == 'O' && board[1][1] == 'O') || (board[0][0] == 'O' && board[2][2] == 'O') || (board[1][1] == 'O' && board[2][2] == 'O'))
        {
            if (board[2][2] == '.' && board[0][0] == 'O' && board[1][1] == 'O') { x = 2; y = 2; return; }
            if (board[1][1] == '.' && board[0][0] == 'O' && board[2][2] == 'O') { x = 1; y = 1; return; }
            if (board[0][0] == '.' && board[1][1] == 'O' && board[2][2] == 'O') { x = 0; y = 0; return; }
        }
        if ((board[0][2] == 'O' && board[1][1] == 'O') || (board[0][2] == 'O' && board[2][0] == 'O') || (board[1][1] == 'O' && board[2][0] == 'O'))
        {
            if (board[2][0] == '.' && board[0][2] == 'O' && board[1][1] == 'O') { x = 0; y = 2; return; }
            if (board[1][1] == '.' && board[0][2] == 'O' && board[2][0] == 'O') { x = 1; y = 1; return; }
            if (board[0][2] == '.' && board[1][1] == 'O' && board[2][0] == 'O') { x = 2; y = 0; return; }
        }
    }
    return;
}
int main()
{
    system("color 0C");
    cout << "  Welcom  \n" << "pleas chose the mode\n" << "[1] 2 players\n" << "[2] With the computer\n";
    cin >> mode;
    system("cls");
    if (mode == 1)
        cout << "\n  'X' Turn \n\n";
    for (int i = 0; i < 9; i++) {
        cout << "    1 2 3" << endl;
        for (int i = 1; i <= 3; i++)
            cout << " " << i << "  " << board[i - 1][0] << " " << board[i - 1][1] << " " << board[i - 1][2] << "\n\n";
        won = checkboard();
        if (won)
        {
            if ((i - 1) % 2 == 0)
            {
                system("cls");
                cout << "\n\n  X WON!! :D  \n\n\n";
                system("pause");
                return 0;
            }
            else
            {
                system("cls");
                cout << "\n\n  Y WON!! :D  \n\n\n";
                system("pause");
                return 0;
            }
        }
        cout << endl << "Next spot in X Y axis:";
        if ((mode == 2 && i % 2 != 0) || (mode == 1))
            cin >> x >> y;
        if (mode == 1 && i % 2 == 0 && board[y - 1][x - 1] == '.')
        {
            board[y - 1][x - 1] = 'X';
            system("cls");
            system("color 09");
            cout << "\n  'O' Turn \n\n";
        }
        else if (i % 2 != 0 && board[y - 1][x - 1] == '.')
        {
            board[y - 1][x - 1] = 'O';
            system("cls");
            system("color 04");
            cout << "\n  'X' Turn \n\n";
        }
        else if (mode == 2 && i % 2 == 0)
        {
            computerplay(x, y, i);
            // cout << x << y;
            board[y][x] = 'X';
            system("cls");
            system("color 04");
            cout << "\n  'O' Turn \n\n";
        }
        else
        {
            system("cls");
            cout << x << y << endl;
            cout << "\n  TRY AGAIN  \n\n";
            i--;
            continue;
        }
    }
    system("color 04");
    cout << "\n  it is a tie :-(  \n\n";
    system("pause");
    return 0;
}
