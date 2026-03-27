#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
ll A, B, C;

double f(double x)
{
    return A * x + B * sin(x) - C;
}

int main()
{
    cin >> A >> B >> C;

    double left = 0;
    double right = 200000;

    double error = 1e-15;

    double prev = 0;
    double mid = (left + right) / 2;
    while (abs(mid - prev) > error)
    {
        double value = f(left) * f(mid);
        if (value < 0)
        {
            right = mid;
            prev = mid;
            mid = (left + right) / 2;
        }
        else if (value > 0)
        {
            left = mid;
            prev = mid;
            mid = (left + right) / 2;
        }
        else
        {
            break;
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << round(mid * 1e6) / 1e6;
}