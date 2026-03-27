#include <iostream>

using namespace std;

int arr[10000];
int n;
int dp[10000];

int max(int a, int b)
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

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(max(arr[0] + arr[1], arr[1] + arr[2]), arr[0] + arr[2]);

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(max(dp[i - 1], dp[i - 2] + arr[i]), arr[i] + arr[i - 1] + dp[i - 3]);
    }
    cout << dp[n - 1];
}