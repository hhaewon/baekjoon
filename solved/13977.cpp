#include <iostream>
#define MOD 1000000007
#define MAXN 4000000
using namespace std;

typedef long long ll;
ll fact[MAXN + 1];
ll factInverse[MAXN + 1];

ll pow(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    while (y)
    {
        if (y % 2 == 1)
        {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

void solve()
{
    ll N, K;
    cin >> N >> K;

    ll res = (fact[N] * factInverse[N - K]) % MOD;
    res = (res * factInverse[K]) % MOD;
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int M;
    cin >> M;

    fact[0] = 1;
    factInverse[0] = 1;
    fact[1] = 1;
    factInverse[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    factInverse[MAXN] = pow(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; i--)
    {
        factInverse[i] = factInverse[i + 1] * (i + 1) % MOD;
    }

    for (int i = 0; i < M; i++)
    {
        solve();
    }
}

// cin.tie(NULL), ios::sync_with_stdio(false); 까먹지 마.