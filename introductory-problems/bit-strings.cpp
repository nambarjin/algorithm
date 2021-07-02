/*
    Time limit: 1.00 s Memory limit: 512 MB
    Your task is to calculate the number of bit strings of length n.

    For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.

    Input

    The only input line has an integer n.

    Output

    Print the result modulo 109+7.

    Constraints
    1≤n≤106
    Example

    Input:
    3

    Output:
    8
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long long n, result = 1;
    cin >> n;
    for(long long i = 0; i < n; i++) {
        result *= 2;
        result = result % (long long)(pow(10, 9) + 7);
    }
    cout << result << endl;
    return 0;
}