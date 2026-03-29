#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool prime[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll result;
    cin >> n;
    result = n;
    ll i = 2;

    prime[1] = false;

    while (n > 1)
    {
        if (n % i == 0)
        {
            result = (result / i) * (i - 1);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
        i++;
    }

    cout << result;
}