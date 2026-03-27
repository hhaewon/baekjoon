#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

ll N, D;
ll heights[300000];
ll lasyerCnt;

void solve()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> D;
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }
    sort(heights, heights + N, greater<>());

    ll last = heights[0] - D;
    if (last <= 0)
    {
        for (int i = 0; i < N; i++)
        {
            lasyerCnt += heights[i];
        }
        cout << lasyerCnt;
        return;
    }
    for (int i = 0; heights[i] > last; i++)
    {
        lasyerCnt += heights[i] - last;
    }
    cout << lasyerCnt;
}

int main()
{
    solve();
}