#include <iostream>

using namespace std;

void solve(int a, int d, int x)
{
    int h = 1;
    while (true)
    {
        int start = (h - 1) * a + ((h - 2) * (h - 1) / 2) * d + 1;
        int end = h * a + ((h - 1) * h / 2) * d;

        if (start <= x && x <= end)
        {
            int n = x - start + 1;
            cout << h << " " << n << "\n";
            return;
        }
        h++;
    }
}

int main()
{
    int Q;
    cin >> Q;
    int a, d, x;
    for (int i = 0; i < Q; i++)
    {
        cin >> a >> d >> x;
        solve(a, d, x);
    }
}