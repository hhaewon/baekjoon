#include <iostream>

#define MOD 1000000007
using namespace std;

typedef long long ll;

int max(ll a, ll b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

ll fastPower(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a % MOD;
    }
    if (b % 2 == 0)
    {
        ll half = fastPower(a, b / 2) % MOD;
        return (half * half) % MOD;
    }
    else
    {
        ll half = fastPower(a, b / 2) % MOD;
        return ((half * half) % MOD * a) % MOD;
    }
}

ll cntByMod[100000];
int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        ll temp;
        cin >> temp;
        cntByMod[temp % K]++;
    }

    ll m = K / 2;

    ll result = 1;
    if (K % 2 == 0)
    {
        result = (cntByMod[0] + 1) % MOD;
        // cout << result << "\n";
        for (int i = 1; i <= m - 1; i++)
        {
            // cout << i << " " << cntByMod[i] - 1 << "/ " << "\n";
            result = (result * (fastPower(2, cntByMod[i]) + fastPower(2, cntByMod[K - i]) - 1)) % MOD;

            // cout << result << "\n";
        }
        result = (result * (cntByMod[m] + 1)) % MOD;
        result = (result + MOD - N - 1) % MOD;
    }
    else
    {
        result = (cntByMod[0] + 1) % MOD;
        for (int i = 1; i <= m; i++)
        {
            result = (result * (fastPower(2, cntByMod[i]) + fastPower(2, cntByMod[K - i]) - 1)) % MOD;
        }

        result = (result + MOD - N - 1) % MOD;
    }
    cout << result;
}