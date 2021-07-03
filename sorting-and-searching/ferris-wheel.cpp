/*
    Time limit: 1.00 s Memory limit: 512 MB
    There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

    Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.

    What is the minimum number of gondolas needed for the children?

    Input

    The first input line contains two integers n and x: the number of children and the maximum allowed weight.

    The next line contains n integers p1,p2,…,pn: the weight of each child.

    Output

    Print one integer: the minimum number of gondolas.

    Constraints
    1≤n≤2⋅105
    1≤x≤109
    1≤pi≤x
    Example

    Input:
    4 10
    7 2 3 9

    Output:
    3
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, result = 0;
    cin >> n >> x;
    int P[n];
    for (int i = 0; i < n; i++)
        cin >> P[i];
    sort(P, P + n);
    for (int i = 0, j = n - 1; i < j;)
    {
        if (P[i] + P[j] <= x)
        {
            j--;
            i++;
            result++;
            continue;
        }
        else if (P[i] + P[j] > x)
            j--;
        else
            i++;
    }
    cout << n - result << endl;
    return 0;
}