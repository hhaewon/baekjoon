#include <iostream>

using namespace std;

int n;
string arr[64];

string func(int x, int y, int size)
{
    int flag = 1;
    char former = arr[y][x];

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (former != arr[i][j])
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }

    if (flag)
    {
        string dst(1, former);
        return dst;
    }

    string dst1 = func(x, y, size / 2);
    string dst2 = func(x + size / 2, y, size / 2);
    string dst3 = func(x, y + size / 2, size / 2);
    string dst4 = func(x + size / 2, y + size / 2, size / 2);

    return "(" + dst1 + dst2 + dst3 + dst4 + ")";
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << func(0, 0, n);
}