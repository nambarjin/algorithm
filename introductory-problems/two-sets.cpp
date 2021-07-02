/*
    Time limit: 1.00 s Memory limit: 512 MB
    Your task is to divide the numbers 1,2,…,n long longo two sets of equal sum.

    Input

    The only input line contains an long longeger n.

    Output

    Prlong long "YES", if the division is possible, and "NO" otherwise.

    After this, if the division is possible, prlong long an example of how to create the sets. First, prlong long the number of elements in the first set followed by the elements themselves in a separate line, and then, prlong long the second set in a similar way.

    Constralong longs
    1≤n≤106
    Example 1

    Input:
    7

    Output:
    YES
    4
    1 2 4 7
    3
    3 5 6

    Example 2

    Input:
    6

    Output:
    NO
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, sum = 0;
    vector<long long> nums, rest;
    cin >> n;
    if (n * (n + 1) / 2 % 2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    long long i = n;
    while ((sum + i) < n * (n + 1) / 4)
    {
        sum += i;
        nums.push_back(i);
        i--;
    }

    long long temp;
    if (sum != (n * (n + 1) / 4))
    {
        temp = n * (n + 1) / 4 - sum;
        nums.push_back(temp);
    }
    cout << nums.size() << endl;
    for (long long i = 0; i < (unsigned)nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl
         << n - nums.size() << endl;
    for (long long i = 1; i <= n - (unsigned)nums.size() + 1; i++)
    {
        if (i != temp)
            rest.push_back(i);
    }
    for (long long i = rest.size() - 1; i >= 0; i--)
        cout << rest[i] << " ";
    return 0;
}