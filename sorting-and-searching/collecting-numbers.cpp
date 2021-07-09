/*
    Time limit: 1.00 s Memory limit: 512 MB
    You are given an array that contains each number between 1…n exactly once. Your task is to collect the numbers from 1 to n in increasing order.

    On each round, you go through the array from left to right and collect as many numbers as possible. What will be the total number of rounds?

    Input

    The first line has an integer n: the array size.

    The next line has n integers x1,x2,…,xn: the numbers in the array.

    Output

    Print one integer: the number of rounds.

    Constraints
    1≤n≤2⋅105
    Example

    Input:
    5
    4 2 1 5 3

    Output:
    3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, number, result = 1;
    cin >> n;
    vector<pair <int, int> > numberMp;
    for(int i = 0; i < n; i++){
        cin >> number;
        numberMp.push_back(make_pair(number,i));
    }
    sort(numberMp.begin(), numberMp.end());
    for(int i = 1; i < n; i++)
        if(numberMp[i].second < numberMp[i - 1].second)
            result += 1;
    cout << result << endl;
    return 0;
}
