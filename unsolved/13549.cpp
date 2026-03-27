#include <iostream>
#include <deque>

using namespace std;

#define MAX 222222

int N, K;
int dist[222222];
deque<int> dq;

void solve()
{

    cin >> N >> K;
    for (int i = 0; i <= MAX - 1; i++)
    {
        dist[i] = 1000000000;
    }
    dq.push_back(N);

    dist[N] = 0;
    while (!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();

        if (cur == K)
        {
            cout << dist[K];
            return;
        }

        int jump = cur * 2;
        if (jump <= 200000 && dist[jump] > dist[cur])
        {
            dist[jump] = dist[cur];
            dq.push_front(jump);
        }

        int left = cur - 1;
        int right = cur + 1;
        if (left >= 0 && dist[left] > dist[cur] + 1)
        {
            dist[left] = dist[cur] + 1;
            dq.push_back(left);
        }
        if (right <= 200000 && dist[right] > dist[cur] + 1)
        {
            dist[right] = dist[cur] + 1;
            dq.push_back(right);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}