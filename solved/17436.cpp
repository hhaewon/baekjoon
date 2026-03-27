#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    ll primes[10];
    for (int i = 0; i < N; i++)
    {
        cin >> primes[i];
    }

    ll result = 0;
    for (ll i = 1; i < (1 << N); i++)
    {
        ll cnt = 0;
        ll target = 1;

        for (ll j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                cnt++;
                target *= primes[j];
            }
        }

        if (cnt % 2 == 1)
        {
            result += M / target;
        }
        else
        {
            result -= M / target;
        }
    }

    cout << result;
}