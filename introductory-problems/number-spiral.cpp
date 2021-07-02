/*
    Time limit: 1.00 s Memory limit: 512 MB
    A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

    Your task is to find out the number in row y and column x.

    Input

    The first input line contains an integer t: the number of tests.

    After this, there are t lines, each containing integers y and x.

    Output

    For each test, print the number in row y and column x.

    Constraints
    1≤t≤105
    1≤y,x≤109
    Example

    Input:
    3
    2 3
    1 1
    4 2

    Output:
    8
    1
    15
*/


#include <iostream>
#include <vector>
using namespace std;

long long calcValue(pair<long long, long long> coordinate)
{
    long long x = coordinate.first, y = coordinate.second;
    if(x >= y) {
        if(x % 2 == 0) 
            return x * x - y + 1;
        return x * x - (2 * x - 1) + 1 + y - 1; 
    }
    if(y % 2 == 0)
        return y * y - (2 * y -1) + 1 + x - 1;
    return y * y - x + 1;
}

int main()
{
    long long t;
    vector< pair<long long, long long> > coords;
    cin >> t;
    long long x, y;
    for (long long i = 0; i < t; i++)
    {
        cin >> x >> y;
        coords.push_back(make_pair(x, y));
    }
    for (long long i = 0; i < t; i++)
        cout << calcValue(coords[i]) << endl;
    return 0;
}