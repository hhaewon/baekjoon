#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

ll arr[18];

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, L, R;
    cin >> N >> L >> R;

    set<ll> a;
    for (ll i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        a.insert(x);
    }

    int idx = 0;
    for (ll x : a)
    {
        arr[idx++] = x;
    }
    N = a.size();
    ll result = 0;

    if (a.count(1))
    {
        cout << R - L + 1;
        return 0;
    }
    for (ll i = 1; i < (1LL << N); i++)
    {
        ll target = 1;
        ll cnt = 0;
        bool overflow = false;
        for (ll j = 0; j < N; j++)
        {
            if (i & (1LL << j))
            {
                cnt++;
                ll g = gcd(target, arr[j]);
                ll factor = arr[j] / g;
                if (target > R / factor)
                {
                    overflow = true;
                    break;
                }
                target = target * factor;
            }
        }
        if (overflow)
        {
            continue;
        }
        if (cnt % 2 == 1)
        {
            result += R / target - (L - 1) / target;
        }
        else
        {
            result -= R / target - (L - 1) / target;
        }
    }

    cout << result;
}