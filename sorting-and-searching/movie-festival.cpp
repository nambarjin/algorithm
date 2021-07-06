/*
    Time limit: 1.00 s Memory limit: 512 MB
    In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?

    Input

    The first input line has an integer n: the number of movies.

    After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.

    Output

    Print one integer: the maximum number of movies.

    Constraints
    1≤n≤2⋅105
    1≤a<b≤109
    Example

    Input:
    3
    3 5
    4 9
    5 8

    Output:
    2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, answer = 1;
    cin >> n;
    vector<pair<int, int>> schedules;
    int start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        schedules.push_back(make_pair(end, start));
    }
    sort(schedules.begin(), schedules.end());
    int prev_end = schedules[0].first;
    for (int i = 1; i < n; i++)
        if (schedules[i].second >= prev_end)
        {
            prev_end = schedules[i].first;
            answer++;
        }
    cout << answer << endl;
    return 0;
}