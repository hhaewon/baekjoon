#include <iostream>

using namespace std;

int pow(int x, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}

int s, N, K, R1, R2, C1, C2;

int star(int startx, int starty, int x, int y, int n)
{
    if (n == 0)
    {
        return 0;
    }

    int size = pow(N, n);
    int subSize = size / N;
    int padding = (N - K) / 2;
    int chuckx = (x - startx) / subSize;
    int chuchy = (y - starty) / subSize;
    // cout << size << " " << subSize << " " << padding << " " << chuckx << " " << chuchy << "\n";
    if ((padding <= chuckx && chuckx < N - padding) && (padding <= chuchy && chuchy < N - padding))
    {
        return 1;
    }
    int nextStartX = startx + subSize * chuckx;
    int nextStartY = starty + subSize * chuchy;
    return star(nextStartX, nextStartY, x, y, n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

    for (int i = R1; i <= R2; i++)
    {
        for (int j = C1; j <= C2; j++)
        {
            cout << star(0, 0, i, j, s);
        }
        cout << "\n";
    }
}