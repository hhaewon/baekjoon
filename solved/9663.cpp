#include <iostream>

using namespace std;

int N;
int cnt;

int col[14];   // x좌표같은거
int diag1[27]; // x+y같은거
int diag2[27]; // x-y같은거
int diagsize;

void solve(int y)
{
    if (y == N)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!col[i] && !diag1[y + i] && !diag2[(i - y + diagsize) % diagsize])
        {
            // cout << "y : " << y << ", i : " << i << "\n";
            col[i] = 1;
            diag1[y + i] = 1;
            diag2[(i - y + diagsize) % diagsize] = 1;
            solve(y + 1);
            col[i] = 0;
            diag1[y + i] = 0;
            diag2[(i - y + diagsize) % diagsize] = 0;
        }
    }
}

int main()
{
    cin >> N;
    diagsize = 2 * N - 1;

    for (int i = 0; i < N; i++)
    {
        // cout << "y : " << 0 << ", i : " << i << "\n";
        col[i] = 1;
        diag1[i] = 1;
        diag2[i] = 1;
        solve(1);
        col[i] = 0;
        diag1[i] = 0;
        diag2[i] = 0;
    }

    cout << cnt;
}