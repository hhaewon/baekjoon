#include <iostream>

using namespace std;

int N;
int x[50];

void solve()
{
    if (N == 1)
    {
        cout << "A";
        return;
    }

    if (N == 2)
    {
        if (x[0] == x[1])
        {
            cout << x[0];
        }
        else
        {
            cout << "A";
        }
        return;
    }

    int a;
    int b;

    if (x[0] != x[1])
    {
        if ((x[1] - x[2]) % (x[0] - x[1]) != 0)
        {
            cout << "B";
            return;
        }
        a = (x[1] - x[2]) / (x[0] - x[1]);
        b = x[1] - x[0] * a;

        int flag = 1;
        for (int i = 2; i < N; i++)
        {
            if (x[i] != a * x[i - 1] + b)
            {
                flag = 0;
                break;
            }
        }

        if (!flag)
        {
            cout << "B";
        }
        else
        {
            cout << a * x[N - 1] + b;
        }
    }
    else
    {
        if (x[1] != x[2])
        {
            cout << "B";
            return;
        }
        else
        {
            int flag = 1;

            for (int i = 2; i < N; i++)
            {
                if (x[i] != x[0])
                {
                    flag = 0;
                    break;
                }
            }

            if (!flag)
            {
                cout << "B";
            }
            else
            {
                cout << x[0];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }

    solve();
}