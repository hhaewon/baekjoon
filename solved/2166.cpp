#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int N;
ll arr[10000][2];

double result = 0;

double area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    return ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 1; i < N - 1; i++)
    {
        result += area(arr[0][0], arr[0][1], arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1]);
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(result) / 2.0;
}