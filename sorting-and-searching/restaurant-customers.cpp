/*
    Time limit: 1.00 s Memory limit: 512 MB
    You are given the arrival and leaving times of n customers in a restaurant.

    What was the maximum number of customers?

    Input

    The first input line has an integer n: the number of customers.

    After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.

    You may assume that all arrival and leaving times are distinct.

    Output

    Print one integer: the maximum number of customers.

    Constraints
    1≤n≤2⋅105
    1≤a<b≤109
    Example

    Input:
    3
    5 8
    2 4
    3 9

    Output:
    2
*/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n, start, end, current = 0, result = 0;
    map<int, char> ioMp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        ioMp[start] = 'S';
        ioMp[end] = 'E';
    }
    map<int, char>::iterator it;
    for (it = ioMp.begin(); it != ioMp.end(); it++)
    {
        if (it->second == 'S')
            current += 1;
        if (it->second == 'E')
            current -= 1;
        result = max(current, result);
    }
    cout << result << endl;
    return 0;
}