#include <iostream>

using namespace std;

#define MOD 1000000000

typedef long long ll;

ll n;
void solve()
{
    if (n == 0)
    {
        cout << "0\n0";
        return;
    }
    if (n == 1)
    {
        cout << "1\n1";
        return;
    }
    if (n == -1)
    {
        cout << "1\n1";
        return;
    }
    long long prevprev = 0;
    long long prev = 1;
    long long cur;
    int abs = n > 0 ? n : -n;
    for (int i = 2; i <= abs; i++)
    {
        cur = (prevprev + prev) % MOD;
        prevprev = prev;
        prev = cur;
    }

    if (n > 0)
    {
        cout << "1\n";
        cout << cur;
    }
    else
    {
        if (n % 2 == 0)
        {
            cout << "-1\n";
            cout << cur;
        }
        else
        {
            cout << "1\n";
            cout << cur;
        }
    }
}

int main()
{
    cin >> n;
    solve();
}