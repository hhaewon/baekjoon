#include <iostream>

using namespace std;

int A[50][50];
int B[50][50];

int N, M;
int different[50][50];
int cntDiff[50][50];  // i~i+2, j~j+2 다른 거 개수
bool visited[50][50]; // 이미 한 변환?

pair<int, int> maxDiff()
{
    int max = 0;
    pair<int, int> result;
    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            if (cntDiff[i][j] > max && !visited[i][j])
            {
                max = cntDiff[i][j];
                result.first = i;
                result.second = j;
            }
        }
    }

    if (max == 0)
    {
        return {-1, -1};
    }
    return result;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            A[i][j] = temp[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {

        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            B[i][j] = temp[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] == B[i][j])
            {
                different[i][j] = 0;
            }
            else
            {
                different[i][j] = 1;
            }
        }
    }
    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            for (int k = 0; k <= 2; k++)
            {
                for (int l = 0; l <= 2; l++)
                {
                    cntDiff[i][j] += different[i + k][j + l];
                }
            }
        }
    }

    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            cout << cntDiff[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "----\n";
    int cnt = 0;

    while (true)
    {
        pair<int, int> maxXY = maxDiff();
        // cout << maxXY.first << " " << maxXY.second << "\n";
        if (maxXY.first == -1)
        {
            break;
        }
        int x = maxXY.first;
        int y = maxXY.second;
        visited[x][y] = true;
        cnt++;

        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                different[x + i][y + j] = different[x + i][y + j] == 1 ? 0 : 1;
            }
        }

        for (int i = 0; i + 2 < N; i++)
        {
            for (int j = 0; j + 2 < M; j++)
            {
                cntDiff[i][j] = 0;
                for (int k = 0; k <= 2; k++)
                {
                    for (int l = 0; l <= 2; l++)
                    {
                        cntDiff[i][j] += different[i + k][j + l];
                    }
                }
            }
        }

        for (int i = 0; i + 2 < N; i++)
        {
            for (int j = 0; j + 2 < M; j++)
            {
                cout << cntDiff[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "----\n";
    }

    int flag = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (different[i][j])
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
        cout << cnt;
    }
    else
    {
        cout << -1;
    }
}