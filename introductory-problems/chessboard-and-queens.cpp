/*
    Time limit: 1.00 s Memory limit: 512 MB
    Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

    How many possible ways are there to place the queens?

    Input

    The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

    Output

    Print one integer: the number of ways you can place the queens.

    Example

    Input:
    ........
    ........
    ..*.....
    ........
    ........
    .....**.
    ...*....
    ........

    Output:
    65
*/

#include <iostream>
#include <math.h>
using namespace std;

string board[8];

int main()
{
    int result = 0;
    for (int i = 0; i < 8; i++)
        cin >> board[i];
    for (int i = 0; i < 8; i++)
    {
        if (board[0][i] == '*')
            continue;
        for (int j = 0; j < 8; j++)
        {
            if (board[1][j] == '*' || abs(i - j) == 1 || i == j)
                continue;
            for (int k = 0; k < 8; k++)
            {
                if (board[2][k] == '*' || abs(j - k) == 1 || abs(i - k) == 2 || j == k || k == i)
                    continue;
                for (int l = 0; l < 8; l++)
                {
                    if (board[3][l] == '*' || abs(l - k) == 1 || abs(l - j) == 2 || abs(l - i) == 3 || l == i || l == j || l == k)
                        continue;
                    for (int m = 0; m < 8; m++)
                    {
                        if (board[4][m] == '*' || abs(m - l) == 1 || abs(m - k) == 2 || abs(m - j) == 3 || abs(m - i) == 4 || m == i || m == j || m == k || m == l)
                            continue;
                        for (int n = 0; n < 8; n++)
                        {
                            if (board[5][n] == '*' || abs(n - m) == 1 || abs(n - l) == 2 || abs(n - k) == 3 || abs(n - j) == 4 || abs(n - i) == 5 || n == i || n == j || n == k || n == l || n == m)
                                continue;
                            for (int o = 0; o < 8; o++)
                            {
                                if (board[6][o] == '*' || abs(o - n) == 1 || abs(o - m) == 2 || abs(o - l) == 3 || abs(o - k) == 4 || abs(o - j) == 5 || abs(o - i) == 6 || o == n || o == m || o == l || o == k || o == i || o == j)
                                    continue;
                                for (int p = 0; p < 8; p++)
                                {
                                    if (board[7][p] == '*' || abs(p - o) == 1 || abs(p - n) == 2 || abs(p - m) == 3 || abs(p - l) == 4 || abs(p - k) == 5 || abs(p - j) == 6 || abs(p - i) == 7 || p == i || p == j || p == k || p == l || p == n || p == o || p == n || p == m)
                                        continue;
                                    result += 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}
