/*
    Time limit: 1.00 s Memory limit: 512 MB
    A Gray code is a list of all 2n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).

    Your task is to create a Gray code for a given length n.

    Input

    The only input line has an integer n.

    Output

    Print 2n lines that describe the Gray code. You can print any valid solution.

    Constraints
    1≤n≤16
    Example

    Input:
    2

    Output:
    00
    01
    11
    10
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int rowCount = pow(2, n);
    string grayCode[rowCount];
    for (int i = 1; i <= n; i++)
    {
        int repeatCount = pow(2, n - i);
        bool currentIsZero = true;
        for (int j = 0, counter = 1; j < rowCount; j++, repeatCount--)
        {
            if (repeatCount == 0)
            {
                counter++;
                repeatCount = pow(2, n - i);
                if (counter % 2 != 1)
                    currentIsZero = !currentIsZero;
            }
            if (currentIsZero)
                grayCode[j] += "0";
            else
                grayCode[j] += "1";
        }
    }

    for (int i = 0; i < rowCount; i++)
        cout << grayCode[i] << endl;
    return 0;
}