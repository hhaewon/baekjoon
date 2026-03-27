#include <iostream>
typedef long long ll;
using namespace std;

ll N, M, k;
ll temp;
ll R[100001];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        R[temp] = i;
    }

    ll CW_T = 0;
    ll CCW_T = 0;

    for (int i = 1; i < M; i++)
    {
        k = (CW_T - R[i]) / N + 1;
        CW_T = k * N + R[i];
    }

    for (int i = N; i >= M; i--)
    {
        k = (CCW_T - R[i]) / N + 1;
        CCW_T = N * k + R[i];
    }

    if (CW_T > CCW_T)
    {
        cout << "CCW";
    }
    else if (CW_T < CCW_T)
    {
        cout << "CW";
    }
    else
    {
        cout << "EQ";
    }
}