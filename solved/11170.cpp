#include <iostream>

using namespace std;

int func(int a)
{
    if (a == 0)
    {
        return 1;
    }
    int cnt = 0;
    while (a > 0)
    {
        if (a % 10 == 0)
        {
            cnt++;
        }
        a = a / 10;
    }
    return cnt;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M;
        cin >> N >> M;
        int result = 0;

        for (int j = N; j <= M; j++)
        {
            result += func(j);
        }
        cout << result << "\n";
    }
}