#include <iostream>
using namespace std;

typedef long long ll;

ll m;

ll mpow(ll x, ll y)
{
    x = x % m;
    ll res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            res = (res * x) % m;
        }
        y /= 2;
        x = (x * x) % m;
    }
    return res;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    ll a, c, s, x1, x2;
    cin >> m >> s >> x1 >> x2;
    ll y1 = (x1 - x2 + m) % m;
    ll y2 = mpow((s - x1 + m) % m, m - 2);
    a = (y1 * y2) % m;
    c = (x1 - a * s % m + m) % m;
    cout << a << " " << c;
}

// -들어가면 m 더하고 m으로 나머지 구하기
