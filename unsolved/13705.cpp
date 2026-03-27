#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;

typedef long long ll;
ll A, B, C;

int n = 100;
long double sint(long double x)
{
    x = fmod(x, 2 * PI);
    if (x > PI)
        x -= 2 * PI;
    else if (x < -PI)
        x += 2 * PI;

    long double result = 0;
    long double target = x;
    for (int i = 1; i <= n; i++)
    {
        result += target;
        target *= (-1) * x * x / ((2 * i) * (2 * i + 1));
    }
    return result;
}

long double f(long double x)
{
    return A * x + B * sint(x) - C;
}

int main()
{
    cin >> A >> B >> C;

    long double left = 0;
    long double right = 200000;

    long double error = 1e-25;

    while (right - left > error)
    {
        long double mid = (left + right) / 2;
        long double value = f(left) * f(mid);
        if (value < 0)
        {
            right = mid;
        }
        else if (value > 0)
        {
            left = mid;
        }
        else
        {
            break;
        }
    }
    printf("%.6f", (left + right) / 2);
}