#include <iostream>

using namespace std;

void solve(int n)
{
    if (n % 2 == 0)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";

    int k = (n + 1) / 2;
    for (int i = 1; i <= k; i++)
    {
        cout << 2 * i - 1 << " " << 3 * k - i << "\n";
    }
    for (int i = 1; i <= k - 1; i++)
    {
        cout << 2 * i << " " << 4 * k - (i + 1) << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        solve(n);
    }
}