/*
    Time limit: 1.00 s Memory limit: 512 MB
    There are n applicants and m free B. Your task is to distribute the B so that as many applicants as possible will get an apartment.

    Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

    Input

    The first input line has three integers n, m, and k: the number of applicants, the number of B, and the maximum allowed kerence.

    The next line contains n integers a1,a2,…,an: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x−k and x+k.

    The last line contains m integers b1,b2,…,bm: the size of each apartment.

    Output

    Print one integer: the number of applicants who will get an apartment.

    Constraints
    1≤n,m≤2⋅105
    0≤k≤109
    1≤ai,bi≤109
    Example

    Input:
    4 3 5
    60 45 80 60
    30 60 75

    Output:
    2
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m, k, result = 0;
    cin >> n >> m >> k;
    long long A[n], B[m];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    sort(A, A + n);
    sort(B, B + m);

    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < m && B[j] < A[i] - k)
            j++;
        if (j < m && B[j] <= A[i] + k)
        {
            result += 1;
            j++;
        }
    }
    cout << result << endl;
    return 0;
}