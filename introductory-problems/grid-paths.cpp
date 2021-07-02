/*
    Time limit: 1.00 s Memory limit: 512 MB
    There are 88418 paths in a 7×7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).

    For example, the path

    corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.

    You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.

    Input

    The only input line has a 48-character string of characters ?, D, U, L and R.

    Output

    Print one integer: the total number of paths.

    Example

    Input:
    ??????R??????U??????????????????????????LD????D?

    Output:
    201
*/

#include <iostream>
using namespace std;

string path;
bool visited[7][7];
int result = 0;

bool ifPossible(int i, int j)
{
    if (!visited[i][j] && i < 7 && i >= 0 && j < 7 && j >= 0)
        return true;
    return false;
}

void calcAll(int i, int j, int move)
{
    visited[i][j] = true;
    if (i == 6 && j == 0)
    {
        if (move == 48)
            result += 1;
    }
    else
    {
        if (path[move] == '?' || path[move] == 'D') //inputbound
            if (ifPossible(i + 1, j))
                if (!(!ifPossible(i + 2, j) && ifPossible(i + 1, j - 1) && ifPossible(i + 1, j + 1))) // selfbound
                    calcAll(i + 1, j, move + 1);
        if (path[move] == '?' || path[move] == 'U')
            if (ifPossible(i - 1, j))
                if (!(!ifPossible(i - 2, j) && ifPossible(i - 1, j - 1) && ifPossible(i - 1, j + 1)))
                    calcAll(i - 1, j, move + 1);
        if (path[move] == '?' || path[move] == 'L')
            if (ifPossible(i, j - 1))
                if (!(!ifPossible(i, j - 2) && ifPossible(i + 1, j - 1) && ifPossible(i - 1, j - 1)))
                    calcAll(i, j - 1, move + 1);
        if (path[move] == '?' || path[move] == 'R')
            if (ifPossible(i, j + 1))
                if (!(!ifPossible(i, j + 2) && ifPossible(i + 1, j + 1) && ifPossible(i - 1, j + 1)))
                    calcAll(i, j + 1, move + 1);
    }
    visited[i][j] = false;
}

int main()
{
    cin >> path;
    calcAll(0, 0, 0);
    cout << result << endl;
    return 0;
}