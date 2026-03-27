#include <iostream>
#include <queue>
using namespace std;

void solve()
{
    int M;
    cin >> M;
    int x;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    cout << M / 2 + 1 << "\n";
    for (int i = 0; i < M; i++)
    {
        cin >> x;
        if (i % 2 == 0)
        {
            maxHeap.push(x);
            if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top())
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(temp);
            }
            cout << maxHeap.top() << " ";
            if (i % 20 == 18)
            {
                cout << "\n";
            }
        }
        else
        {
            minHeap.push(x);
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }
}