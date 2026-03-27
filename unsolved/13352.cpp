#include <iostream>
using namespace std;

#define MAX_N 100000

typedef long long ll;

ll N;
ll points[MAX_N][2];
ll x1, y1, x2, y2, x3, y3;

// points[i], points[j], points[k] 한 직선 위에 있는지
bool collinear(ll i, ll j, ll k)
{
    x1 = points[i][0];
    y1 = points[i][1];
    x2 = points[j][0];
    y2 = points[j][1];
    x3 = points[k][0];
    y3 = points[k][1];
    return (x2 - x3) * (y1 - y2) == (x1 - x2) * (y2 - y3);
}

bool solve()
{
    if (N <= 4)
    {
        return true;
    }

    if (collinear(0, 1, 2))
    {
        ll i = 3;
        for (i = 3; i < N; i++)
        {
            if (!collinear(0, 1, i))
            {
                break;
            }
        }
        ll temp1 = i;
        for (i = temp1 + 1; i < N; i++)
        {
            if (!collinear(0, 1, i))
            {
                break;
            }
        }
        ll temp2 = i;

        for (i = temp2 + 1; i < N; i++)
        {
            if (!collinear(0, 1, i) && !collinear(temp1, temp2, i))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        // 0, 1 한 직선 위에
        ll i = 3;
        for (; i < N; i++)
        {
            if (!collinear(0, 1, i))
            {
                break;
            }
        }

        if (i == N)
        {
            return true;
        }

        ll temp = i;
        for (i = temp + 1; i < N; i++)
        {
            if (!collinear(0, 1, i) && !collinear(2, temp, i))
            {
                break;
            }
        }

        if (i == N)
        {
            return true;
        }

        // 0, 2 한 직선 위에

        i = 3;
        for (; i < N; i++)
        {
            if (!collinear(0, 2, i))
            {
                break;
            }
        }

        if (i == N)
        {
            return true;
        }

        temp = i;
        for (i = temp + 1; i < N; i++)
        {
            if (!collinear(0, 2, i) && !collinear(1, temp, i))
            {
                break;
            }
        }

        if (i == N)
        {
            return true;
        }

        // 1, 2 한 직선 위에
        i = 3;
        for (; i < N; i++)
        {
            if (!collinear(1, 2, i))
            {
                break;
            }
        }

        if (i == N)
        {
            return true;
        }

        temp = i;
        for (i = temp + 1; i < N; i++)
        {
            if (!collinear(1, 2, i) && !collinear(0, temp, i))
            {
                break;
            }
        }

        if (i == N)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    if (solve())
    {
        cout << "success";
    }
    else
    {
        cout << "failure";
    }
}