#include <iostream>

typedef long long ll;

using namespace std;

bool isEvenFactor(ll n)
{
    ll i = 2;
    ll cnt = 0;
    while (n > 1)
    {
        if (n % i == 0)
        {
            n = n / i;
            cnt++;
        }
        else
        {
            if (i % 2 == 1 && cnt % 2 == 1)
            {
                return true;
            }
            cnt = 0;
            i++;
        }
    }
    if (i % 2 == 1 && cnt % 2 == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    ll m;
    cin >> m;
    ll cnt = 0;

    for (ll i = 1; i <= m; i++)
    {
        if (isEvenFactor(i))
        {
            cnt++;
        }
    }
    cout << cnt;
}