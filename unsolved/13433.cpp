#include <iostream>
#include <cmath>

using namespace std;

bool used[8];
double minD = -1;

int N;
double R[8];
double permutation[8];

void solve(int index)
{
    if (index == N - 1)
    {
        double last = 0;
        for (int i = 0; i < N; i++)
        {
            if (!used[i])
            {
                last = R[i];
                break;
            }
        }
        permutation[index] = last;
        double result = 0;
        for (int i = 0; i < N - 1; i++)
        {
            result += sqrt(permutation[i] * permutation[i + 1]);
        }
        result *= 2;
        if (minD == -1 || result < minD)
        {
            cout << permutation[0] << " " << permutation[1] << " " << permutation[2] << " " << permutation[3] << " " << permutation[4] << " " << result << "\n";
            minD = result;
        }
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (!used[i])
        {
            permutation[index] = R[i];
            used[i] = true;
            solve(index + 1);
            used[i] = false;
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
        cin >> R[i];
    }
    solve(0);
    cout.precision(20);
    cout << minD;
}