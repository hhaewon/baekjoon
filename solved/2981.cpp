#include <bits/stdc++.h>
using namespace std;

int arr[100];

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> arr[i];
    }

    int x = 0;
    for (int i = 0; i < M - 1; i++)
    {
        x = gcd(x, abs(arr[i + 1] - arr[i]));
    }
    for (int i = 2; i <= x; i++)
    {
        if (x % i == 0)
        {
            cout << i << " ";
        }
    }
}