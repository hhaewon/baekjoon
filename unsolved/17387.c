#include <stdio.h>

typedef long long ll;

// 반시계?
int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    return (x1 - x2) * (y3 - y2) - (x3 - x2) * (y1 - y2) > 0;
}

int main()
{
    ll x1, x2, x3, x4, y1, y2, y3, y4;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);

    if (ccw(x1, y1, x2, y2, x3, y3) && !ccw(x1, y1, x2, y2, x4, y4))
    {
        int a1 = ccw(x1, y1, x3, y3, x4, y4);
        int a2 = ccw(x4, y4, x3, y3, x2, y2);
        if (a1 == a2)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    else if (!ccw(x1, y1, x2, y2, x3, y3) && ccw(x1, y1, x2, y2, x4, y4))
    {

        int a1 = ccw(x1, y1, x3, y3, x4, y4);
        int a2 = ccw(x4, y4, x3, y3, x2, y2);
        if (a1 == a2)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    else
    {
        printf("0");
    }
}