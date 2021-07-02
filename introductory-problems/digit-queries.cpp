/*
    Time limit: 1.00 s Memory limit: 512 MB
    Consider an infinite string that consists of all positive integers in increasing order:

    12345678910111213141516171818202122232425...

    Your task is to process q queries of the form: what is the digit at position k in the string?

    Input

    The first input line has an integer q: the number of queries.

    After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.

    Output

    For each query, print the corresponding digit.

    Constraints
    1≤q≤1000
    1≤k≤1018
    Example

    Input:
    3
    7
    18
    12

    Output:
    7
    4
    1
*/

#include <iostream>
#include <math.h>
using namespace std;

unsigned long long intervals[19];

void setIntervals()
{
    intervals[0] = 0;
    for (int i = 1; i <= 18; i++)
    {
        intervals[i] += intervals[i - 1] + (long long)(pow(10, i) - (long long)pow(10, i - 1)) * i;
        // cout << i << " : " << intervals[i] << endl;
    }
}

int main()
{
    int q;
    cin >> q;
    unsigned long long k[q], target;
    setIntervals();
    for (int i = 0; i < q; i++)
        cin >> k[i];
    for (int i = 0; i < q; i++)
    {
        if (k[i] < 10)
            cout << k[i] << endl;
        else
        {
            int lowerBoundIndex = 0;
            for (int j = 0; j <= 18; j++)
            {
                if (intervals[j] > k[i])
                    break;
                lowerBoundIndex++;
            }
            target = (long long)pow(10, lowerBoundIndex - 1) - 1 + (k[i] - intervals[lowerBoundIndex - 1]) / lowerBoundIndex;
            if ((k[i] - intervals[lowerBoundIndex - 1]) % lowerBoundIndex > 0)
                target += 1;
            unsigned long long diff = (k[i] - intervals[lowerBoundIndex - 1]) % lowerBoundIndex;
            diff -= 1;
            string str;
            str = to_string(target);
            if (diff != -1)
                cout << str[diff] << endl;
            else
                cout << str[str.length() - 1] << endl;
        }
    }
    return 0;
}