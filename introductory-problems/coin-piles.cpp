/*
    Time limit: 1.00 s Memory limit: 512 MB
    You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.

    Your task is to efficiently find out if you can empty both the piles.

    Input

    The first input line has an integer t: the number of tests.

    After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.

    Output

    For each test, print "YES" if you can empty the piles and "NO" otherwise.

    Constraints
    1≤t≤105
    0≤a,b≤109
    Example

    Input:
    3
    2 1
    2 2
    3 3

    Output:
    YES
    NO
    YES
*/

#include <iostream>
#include <vector>
using namespace std;

string calcPossible(pair<long long, long long> coins)
{
    long long diff = max(coins.first, coins.second) - min(coins.first, coins.second);
    if(diff > min(coins.first, coins.second))
        return "NO";
    return "YES";
}

int main()
{
    long long t, a, b;
    cin >> t;
    vector< pair<int, int> > coins;
    for (long long i = 0; i < t; i++)
    {
        cin >> a >> b;
        coins.push_back(make_pair(a, b));
    }

    for (long long i = 0; i < t; i++)
        if (coins[i].first + coins[i].second == 0)
            cout << "YES" << endl;
        else if ((coins[i].first + coins[i].second) % 3 != 0)
            cout << "NO" << endl;
        else
            cout << calcPossible(coins[i]) << endl;
    return 0;
}