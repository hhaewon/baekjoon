#include <iostream>

using namespace std;

#define MAX_N 100000

int n;
int arr[MAX_N];
int A[MAX_N];
int B[MAX_N];
int dp1[MAX_N];
int dp2[MAX_N];
int totalSum;

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

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    A[0] = arr[0];
    dp1[0] = min(A[0], 0);

    if (n == 1)
    {
        cout << arr[0];
        return;
    }

    if (n == 2)
    {
        cout << max(max(arr[0] + arr[1], arr[0]), arr[1]);
        return;
    }

    for (int i = 1; i < n; i++)
    {
        A[i] = A[i - 1] + arr[i];

        dp1[i] = min(dp1[i - 1], A[i]);
    }
    totalSum = A[n - 1];
    dp2[n - 1] = min(arr[n - 1], 0);
    B[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        B[i] = B[i + 1] + arr[i];
        dp2[i] = min(dp2[i + 1], B[i]);
    }

    int result = totalSum - dp2[1];
    for (int i = 1; i < n - 1; i++)
    {
        result = max(result, totalSum - (dp1[i - 1] + dp2[i + 1]));
    }
    result = max(result, totalSum - dp1[n - 2]);

    cout << result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}