/*
    Time limit: 1.00 s Memory limit: 512 MB
    You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?

    Input

    The first input line has an integer n: the number of coins.

    The second line has n integers x1,x2,…,xn: the value of each coin.

    Output

    Print one integer: the smallest coin sum.

    Constraints
    1≤n≤2⋅105
    1≤xi≤109
    Example

    Input:
    5
    2 9 1 2 7

    Output:
    6
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long X[n], result = 1;
    for (int i = 0; i < n; i++)
        cin >> X[i];
    sort(X, X + n);
    for (int i = 0; i < n; i++)
    {
        if (X[i] > result)
            break;
        result += X[i];
    }
    cout << result << endl;
    return 0;
}