/*
    Time limit: 1.00 s Memory limit: 512 MB
    There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.

    Each customer announces the maximum price he or she is willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

    Input

    The first input line contains integers n and m: the number of tickets and the number of customers.

    The next line contains n integers h1,h2,…,hn: the price of each ticket.

    The last line contains m integers t1,t2,…,tm: the maximum price for each customer.

    Output

    Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.

    If a customer cannot get any ticket, print −1.

    Constraints
    1≤n,m≤2⋅105
    1≤hi,ti≤109
    Example

    Input:
    5 3
    5 3 7 8 5
    4 8 3

    Output:
    3
    8
    -1
*/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n, m, x;
    cin >> n >> m;
    int T[m];
    map<int, int> H;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        H[x] += 1;
    }
    for (int i = 0; i < m; i++)
        cin >> T[i];
    map<int, int>::iterator it, it2;
    for (int i = 0; i < m; i++)
    {
        bool found = false;
        if (H.lower_bound(T[i]) == H.end())
            it2 = H.begin();
        else
            it2 = H.lower_bound(T[i]);
        for (it = it2; it != H.end();)
        {

            if (it->first <= T[i] && it->second > 0)
            {
                found = true;
                cout << it->first << endl;
                it->second -= 1;
                if (it->second == 0)
                    H.erase(it);
                break;
            }
            if (it == H.begin())
                break;
            it--;
        }
        if (!found)
            cout << "-1" << endl;
    }
    return 0;
}
