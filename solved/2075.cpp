#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1500 * 1500];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    // priority_queue<int> pq;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[N * i + j];
        }
    }
    sort(A, A + N * N);
    cout << A[N * N - N];
}
