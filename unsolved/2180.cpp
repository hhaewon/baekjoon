#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
pair<int, int> events[200000]; // a, b

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return (long long)a.first * b.second > (long long)a.second * b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> events[i].first;
        cin >> events[i].second;
    }

    sort(events, events + n, cmp);

    // for (int i = 0; i < n; i++)
    // // {
    // //     cout << events[i].first << " " << events[i].second << "\n";
    // // }
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        t = (((long long)events[i].first + 1) * t + events[i].second) % 40000;
    }
    cout << t;
}