#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> factoriazation(ll n)
{
    vector<ll> result;

    ll i = 2;
    while (n > 1 && i * i <= n)
    {
        if (n % i == 0)
        {
            if (result.size() == 0 || result.back() != i)
            {
                result.push_back(i);
            }
            n = n / i;
        }
        else
        {
            i++;
        }
    }
    if (n > 1 && (result.size() == 0 || result.back() != n))
    {
        result.push_back(n);
    }
    return result;
}

ll solve(ll N, ll A, ll B)
{
    vector<ll> arr = factoriazation(N);

    ll result = 0;
    ll size = arr.size();

    for (ll i = 1; i < (1LL << size); i++)
    {
        ll cnt = 0;
        ll target = 1;
        bool overflow = false;
        for (ll j = 0; j < size; j++)
        {
            if (i & (1LL << j))
            {
                cnt++;

                if (target > B / arr[j])
                {
                    overflow = true;
                    break;
                }
                target *= arr[j];
            }
        }

        if (overflow)
        {
            continue;
        }

        if (cnt % 2 == 1)
        {
            result += B / target - (A - 1) / target;
        }
        else
        {
            result -= B / target - (A - 1) / target;
        }
    }
    return (B - A + 1) - result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        ll A, B, N;
        cin >> A >> B >> N;
        cout << "Case #" << i << ": " << solve(N, A, B) << "\n";
    }
}