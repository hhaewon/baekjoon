#include <iostream>

using namespace std;

typedef long long ll;
bool isSqaure[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll min, max;
    cin >> min >> max;
    int cnt = max - min + 1;
    for (ll i = 2; i * i <= max; i++)
    {
        ll remains = min % (i * i) == 0 ? 0 : 1;
        ll k = min / (i * i) + remains;
        ll j = k * (i * i);
        while (j <= max)
        {
            if (!isSqaure[j - min])
            {

                isSqaure[j - min] = true;
                cnt--;
            }
            j += i * i;
        }
    }
    cout << cnt;
}