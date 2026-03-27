#include <iostream>

using namespace std;

typedef long long ll;
int T;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void solve(ll K, ll N, ll x1, ll y1, ll x2, ll y2)
{
    ll temp = N * (x2 - x1) - K * (y2 - y1);
    if ((N == K || N == -K))
    {
        if (temp != 0)
        {
            cout << "NIE\n";
            return;
        }
        else
        {
            ll c = x2 - x1;
            if (c % gcd(K, N) == 0)
            {
                cout << "TAK\n";
                return;
            }
            else
            {
                cout << "NIE\n";
                return;
            }
        }
    }

    if (temp % (N - K) != 0 || temp % (N + K) != 0)
    {
        cout << "NIE\n";
        return;
    }

    ll b = (temp / (N - K)) / (N + K);
    ll temp2 = x2 - x1 - b * N;
    if (K == 0)
    {
        if (temp2 != 0)
        {
            cout << "NIE\n";
            return;
        }
        else
        {
            cout << "TAK\n";
            return;
        }
    }
    if (temp2 % K != 0)
    {
        cout << "NIE\n";
        return;
    }
    else
    {
        cout << "TAK\n";
    }
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        ll K, N, x1, y1, x2, y2;
        cin >> K >> N >> x1 >> y1 >> x2 >> y2;
        solve(K, N, x1, y1, x2, y2);
    }
}