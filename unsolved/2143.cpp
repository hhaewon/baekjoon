#include <iostream>
#include <algorithm>

using namespace std;

int T, n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    cin >> n;
    int arr[2000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[n + i];
    }
    sort(arr, arr + n + m);
    for (int i = 0; i < n + m; i++)
    {
        cout << arr[i] << "\n";
    }
    int start = 0;
    int end = 0;
    int sum = 0;
    int cnt = 0;
    while (end <= n + m)
    {
        if (T > sum)
        {
            sum += arr[end++];
        }
        else if (T == sum)
        {
            cnt++;
            sum -= arr[start++];
        }
        else
        {
            sum -= arr[start++];
        }
    }

    cout << cnt;
}