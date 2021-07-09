/*
    Time limit: 1.00 s Memory limit: 512 MB
    You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

    Input

    The first input line has two integers n and x: the array size and the target sum.

    The second line has n integers a1,a2,…,an: the array values.

    Output

    Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

    Constraints
    1≤n≤2⋅105
    1≤x,ai≤109
    Example

    Input:
    4 8
    2 7 5 1

    Output:
    2 4
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, x, number, counter = 0, B[2];
    cin >> n >> x;
    map<int, int> A;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        if (number * 2 == x && counter < 2)
        {
            B[counter] = i;
            counter++;
        }
        A[number] = i;
    }
    if (counter >= 2)
    {
        cout << B[0] + 1 << " " << B[1] + 1 << endl;
        return 0;
    }
    map<int, int>::iterator it;
    for (it = A.begin(); it != A.end(); it++)
    {
        if ((A.lower_bound(x - it->first) != A.end()) && A.lower_bound(x - it->first) != it)
        {
            if (A.lower_bound(x - it->first)->first + it->first == x)
            {
                cout << it->second + 1 << " ";
                cout << A.lower_bound(x - it->first)->second + 1 << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
