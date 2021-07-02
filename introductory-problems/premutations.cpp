/*
    Time limit: 1.00 s Memory limit: 512 MB
    A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.

    Given n, construct a beautiful permutation if such a permutation exists.

    Input

    The only input line contains an integer n.

    Output

    Print a beautiful permutation of integers 1,2,…,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".

    Constraints
    1≤n≤106
    Example 1

    Input:
    5

    Output:
    4 2 5 3 1

    Example 2

    Input:
    3

    Output:
    NO SOLUTION
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n <= 3 && n != 1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int start;
    if (n % 2 == 0)
        start = n / 2;
    else
        start = n / 2 + 1;
    cout << start << " ";
    for (int i = n; i >= n / 2 + 1; i--)
    {
        if (i != start)
            cout << i << " ";
        if ((n - i + 1 != start) && (n - i + 1 != i))
            cout << n - i + 1 << " ";
    }
    return 0;
}