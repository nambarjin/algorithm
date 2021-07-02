/*
    Time limit: 1.00 s Memory limit: 512 MB
    There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.

    Input

    The first input line has an integer n: the number of apples.

    The next line has n integers p1,p2,…,pn: the weight of each apple.

    Output

    Print one integer: the minimum difference between the weights of the groups.

    Constraints
    1≤n≤20
    1≤pi≤109
    Example

    Input:
    5
    3 2 7 4 1

    Output:
    1

    Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).
*/

#include <iostream>
#include <cmath>
using namespace std;

int n;

string decToBinary(int decimal)
{
    string result = "";
    for (int i = n; i >= 0; i--)
    {
        int k = decimal >> i;
        if (k & 1)
            result += "1";
        else
            result += "0";
    }
    return result;
}

int main()
{
    cin >> n;
    long long apples[n], sum = 0, result = __LONG_LONG_MAX__;
    for (int i = 0; i < n; i++)
    {
        cin >> apples[i];
        sum += apples[i];
    }
    for(int i = 0; i < pow(2, n); i++) {
        string temp;
        temp = decToBinary(i);
        long long currentSum = 0;
        for(int j = 0; j < n; j++){
            if(temp[j] == '1')
                currentSum += apples[j];
        }
        if(result > abs((sum - currentSum) - currentSum))
            result = abs((sum - currentSum) - currentSum);
    }
    cout << result << endl;
    return 0;
}