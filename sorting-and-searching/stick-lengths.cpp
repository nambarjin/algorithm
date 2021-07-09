/*
    Time limit: 1.00 s Memory limit: 512 MB
    There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.

    You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.

    What is the minimum total cost?

    Input

    The first input line contains an integer n: the number of sticks.

    Then there are n integers: p1,p2,…,pn: the lengths of the sticks.

    Output

    Print one integer: the minimum total cost.

    Constraints
    1≤n≤2⋅105
    1≤pi≤109
    Example

    Input:
    5
    2 3 1 5 2

    Output:
    5
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    long long target, result = 0;
    cin >> n;
    int P[n];
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }
    sort(P, P + n);
    target = P[n / 2];
    for (int i = 0; i < n; i++)
        result += abs(P[i] - target);
    cout << result << endl;
    return 0;
}