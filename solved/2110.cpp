#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
int A[200000];

int main()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A, A + N);

    int left = 1;
    int right = (A[N - 1] - A[0]) / (C - 1);
    int n = 1;
    int former = 0;
    int result = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        n = 1;
        former = 0;
        for (int i = 1; i < N; i++)
        {
            if (A[i] - A[former] >= mid)
            {
                n++;
                former = i;
            }
        }
        if (n >= C)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result;
}