/*
    Time limit: 1.00 s Memory limit: 512 MB
    You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

    Input

    The only input line contains a string of n characters.

    Output

    Print one integer: the length of the longest repetition.

    Constraints
    1≤n≤106
    Example
`
    Input:
    ATTCGGGA

    Output:
    3
*/

#include <iostream>
using namespace std;

int main()
{
    string letters;
    cin >> letters;
    int current = 1, max = 1, size = letters.length();

    for (int i = 1; i < size; i++)
    {
        if (letters[i] == letters[i - 1])
            current++;
        else
            current = 1;
        if (current > max)
            max = current;
    }
    cout << max << endl;
    return 0;
}