#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int G, L;
    cin >> G >> L;
    int ab = L / G;
    int minsum = 200000000;
    int mina = -1;
    int minb = -1;
    for (int a = 1; a <= ab; a++)
    {
        if (ab % a != 0)
        {
            continue;
        }
        int b = ab / a;
        if (gcd(a, b) == 1 && minsum > a + b)
        {
            minsum = a + b;
            mina = a;
            minb = b;
        }
    }

    cout << G * mina << " " << G * minb;
}