/*
    Time limit: 1.00 s Memory limit: 512 MB
    The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom.

    The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.

    Your task is to find a solution that minimizes the number of moves.

    Input

    The only input line has an integer n: the number of disks.

    Output

    First print an integer k: the minimum number of moves.

    After this, print k lines that describe the moves. Each line has two integers a and b: you move a disk from stack a to stack b.

    Constraints
    1≤n≤16
    Example

    Input:
    2

    Output:
    3
    1 2
    1 3
    2 3
*/

#include <iostream>
#include <vector>
using namespace std;

int counter = 0;
vector<string> moves;

void calcTower(int disk, string start, string buffer, string target)
{
    if (disk > 0)
    {
        counter += 1;
        calcTower(disk - 1, start, target, buffer);
        moves.push_back(start + " " + target);
        calcTower(disk - 1, buffer, start, target);
    }
}

int main()
{
    int n;
    cin >> n;
    calcTower(n, "1", "2", "3");
    cout << counter << endl;
    for(int i = 0; i < (signed)moves.size(); i++)
        cout << moves[i] << endl;
    return 0;
}