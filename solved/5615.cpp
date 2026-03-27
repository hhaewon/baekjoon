#include <iostream>
using namespace std;

typedef long long ll;
typedef __int128_t int128;

ll power(ll x, ll y, ll mod)
{
    ll res = 1;
    x = x % mod;
    while (y)
    {
        if (y % 2 == 1)
        {
            res = (ll)(((int128)res * x) % mod);
        }
        y /= 2;
        x = (ll)(((int128)x * x) % mod);
    }
    return res;
}

bool miller(ll n, ll a)
{
    if (a % n == 0)
    {
        return true;
    }

    ll k = n - 1;
    while (k % 2 == 0)
    {
        ll temp = power(a, k, n);
        if (temp == n - 1)
        {
            return true;
        }
        k = k / 2;
    }
    ll temp = power(a, k, n);
    return temp == 1 || temp == n - 1;
}

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0)
    {
        return false;
    }

    ll candi[] = {2, 3, 5, 7, 11};
    for (auto &a : candi)
    {
        if (n == a)
        {
            return true;
        }
        if (!miller(n, a))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    ll x;
    cin >> T;
    int n = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> x;
        if (2 * x + 1 < 9 || isPrime(2 * x + 1))
        {
            n++;
        }
    }
    cout << n;
}

// __int128_t 이용
// a list 최소한으로