#include <iostream>

using namespace std;
int N;

bool isPrime(int x)
{
    if (x == 1)
    {
        return false;
    }
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void recursive(int x, int digits)
{
    if (digits == N)
    {
        cout << x << "\n";
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        int val = 10 * x + i;
        if (isPrime(val))
        {
            recursive(val, digits + 1);
        }
    }
}

int main()
{
    cin >> N;
    recursive(2, 1);
    recursive(3, 1);
    recursive(5, 1);
    recursive(7, 1);
}