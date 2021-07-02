/*
    Time limit: 1.00 s Memory limit: 512 MB
    Your task is to calculate the number of trailing zeros in the factorial n!.

    For example, 20!=2432902008176640000 and it has 4 trailing zeros.

    Input

    The only input line has an integer n.

    Output

    Print the number of trailing zeros in n!.

    Constraints
    1≤n≤109
    Example

    Input:
    20

    Output:
    4
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n, result = 0;
    cin >> n;
    for (int i = 13; i > 0; i--)
        result += n / pow(5, i);
    cout << result << endl;
    return 0;
}