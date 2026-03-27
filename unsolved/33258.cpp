#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

ll N, L;
ll A[100000];

ll getgood(ll x)
{
    ll result = 0;
    ll i = 0;
    for (; A[i] > x; i++)
    {
        result += 2 * (x - A[i]);
    }
    result += x * (N - i);

    return result;
}

ll binSearch()
{
    ll left = 1;
    ll right = 1000000000;
    // cout << left << " " << right << "\n";
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        // cout << "getgood(" << mid << ") : " << getgood(mid) << "\n";
        if (getgood(mid) >= L)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cin >> L;
    sort(A, A + N, greater<>());
    cout << binSearch();
}