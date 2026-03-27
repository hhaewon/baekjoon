#include <iostream>

using namespace std;

bool isComposite[1000001];

bool solve(int N)
{
    for (int i = 2; i < N; i++)
    {
        if (isComposite[i])
        {
            continue;
        }
        for (int j = i; i + j < N; j++)
        {
            if (isComposite[j])
            {
                continue;
            }
            for (int k = j; i + j + k < N; k++)
            {
                if (isComposite[k])
                {
                    continue;
                }
                if (!isComposite[N - i - j - k])
                {
                    cout << i << " " << j << " " << k << " " << N - i - j - k << "\n";
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    isComposite[1] = true;
    for (int i = 2; i * i <= N; i++)
    {
        if (!isComposite[i])
        {
            for (int j = 2; i * j <= N; j++)
            {
                isComposite[i * j] = true;
            }
        }
    }

    bool isPossible = solve(N);
    if (!isPossible)
    {
        cout << -1;
    }
}