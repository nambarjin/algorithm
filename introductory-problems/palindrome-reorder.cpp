/*
    Time limit: 1.00 s Memory limit: 512 MB
    Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

    Input

    The only input line has a string of length n consisting of characters A–Z.

    Output

    Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".

    Constraints
    1≤n≤106
    Example

    Input:
    AAAACACBA

    Output:
    AACABACAA
*/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    string input, result = "", odd = "";
    int oddCounter = 0;
    map<char, int> charmp;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        charmp[input[i]] += 1;
    }
    for (map<char, int>::iterator it = charmp.begin(); it != charmp.end(); it++)
        if (it->second % 2 != 0){
            oddCounter++;
            odd = it->first;
        }
    if (oddCounter > 1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    for (map<char, int>::iterator it = charmp.begin(); it != charmp.end(); it++)
    {
        for (int i = 0; i < it->second / 2; i++)
            result += it->first;
    }
    cout << result;
    cout << odd;
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}