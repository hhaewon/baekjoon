#include <iostream>

using namespace std;

#define MAX_N 1000000

bool isComposite[MAX_N + 1];
int primes[MAX_N];
int numPrimes = 0;

void solve(int n)
{
    for (int i = 0; i < numPrimes; i++)
    {
        if (!isComposite[n - primes[i]])
        {
            cout << n << " = " << primes[i] << " + " << n - primes[i] << "\n";
            return;
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    isComposite[1] = true;

    for (int i = 2; i * i <= MAX_N; i++)
    {
        if (!isComposite[i])
        {
            for (int j = 2 * i; j <= MAX_N; j += i)
            {
                isComposite[j] = true;
            }
        }
    }

    for (int i = 3; i <= MAX_N; i++)
    {
        if (!isComposite[i])
        {
            primes[numPrimes++] = i;
        }
    }

    while (n != 0)
    {
        solve(n);
        cin >> n;
    }
}