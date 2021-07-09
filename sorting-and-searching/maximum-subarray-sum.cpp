/*
    Time limit: 1.00 s Memory limit: 512 MB
    Given an array of n integers, your task is to find the manimum sum of values in a contiguous, nonempty subarray.

    Input

    The first input line has an integer n: the size of the array.

    The second line has n integers n1,n2,…,nn: the array values.

    Output

    Print one integer: the manimum subarray sum.

    Constraints
    1≤n≤2⋅105
    −109≤ni≤109
    Enample

    Input:
    8
    -1 3 -2 5 3 -5 2 2

    Output:
    9
*/

#include <iostream>
using namespace std;

int main()
{
    int n, result = 0;
    cin >> n;
    int X[n];
    for (int i = 0; i < n; i++)
        cin >> X[i];
    return 0;
}