#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K;
pair<ll, ll> jewels[300000];
ll bags[300000];

priority_queue<ll> pq;
bool compare(pair<ll, ll> &i, pair<ll, ll> &j)
{
    return i.first < j.first;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;

    for (ll i = 0; i < N; i++)
    {
        ll m, v;
        cin >> m >> v;
        jewels[i] = {m, v};
    }
    for (ll i = 0; i < K; i++)
    {
        cin >> bags[i];
    }
    sort(jewels, jewels + N, compare);
    sort(bags, bags + K);
    ll index = 0;
    ll result = 0;
    for (ll i = 0; i < K; i++)
    {
        while (index < N && jewels[index].first <= bags[i])
        {
            pq.push(jewels[index].second);
            index++;
        }
        if (pq.empty())
        {
            continue;
        }
        result += pq.top();
        pq.pop();
    }
    cout << result;
}

// 힙 활용 방안이 어려움
// 미리 정렬해놓으면, 특정 무게 이하 보석 들을 다 매번 구할필요없다.