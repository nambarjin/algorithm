/*
    Time limit: 1.00 s Memory limit: 512 MB
    Given a string, your task is to generate all different strings that can be created using its characters.

    Input

    The only input line has a string of length n. Each character is between a–z.

    Output

    First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.

    Constraints
    1≤n≤8
    Example

    Input:
    aabac

    Output:
    20
    aaabc
    aaacb
    aabac
    aabca
    aacab
    aacba
    abaac
    abaca
    abcaa
    acaab
    acaba
    acbaa
    baaac
    baaca
    bacaa
    bcaaa
    caaab
    caaba
    cabaa
    cbaaa
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string input;
    vector<string> result;
    cin >> input;
    sort(input.begin(), input.end());
    do
    {
        result.push_back(input);
    } while (next_permutation(input.begin(), input.end()));
    cout << result.size() << endl;
    for (int i = 0; i < (signed)result.size(); i++)
        cout << result[i] << endl;
    return 0;
}