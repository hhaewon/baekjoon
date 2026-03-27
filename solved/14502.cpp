#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<int, int> convertToxy(int x)
{
    return {x / M, x % M};
}

int isValid(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < M;
}

void dfs(int x, int y, vector<vector<int>> &map)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny) && map[nx][ny] == 0)
        {
            // cout << nx << " " << ny << " " << map[nx][ny] << "\n";
            map[nx][ny] = 3;
            dfs(nx, ny, map);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
    int maxCnt = -1;

    for (int i = 0; i < N * M; i++)
    {
        for (int j = i + 1; j < N * M; j++)
        {
            for (int k = j + 1; k < N * M; k++)
            {
                vector<vector<int>> mapCopy = map;

                pair<int, int> wall1 = convertToxy(i);
                pair<int, int> wall2 = convertToxy(j);
                pair<int, int> wall3 = convertToxy(k);

                if (mapCopy[wall1.first][wall1.second] != 0)
                {
                    break;
                }

                if (mapCopy[wall2.first][wall2.second] != 0)
                {
                    break;
                }

                if (mapCopy[wall3.first][wall3.second] != 0)
                {
                    continue;
                }
                mapCopy[wall1.first][wall1.second] = 1;
                mapCopy[wall2.first][wall2.second] = 1;
                mapCopy[wall3.first][wall3.second] = 1;

                for (int a = 0; a < N; a++)
                {
                    for (int b = 0; b < M; b++)
                    {
                        if (mapCopy[a][b] == 2)
                        {
                            dfs(a, b, mapCopy);
                        }
                    }
                }

                int cnt = 0;
                for (int a = 0; a < N; a++)
                {
                    for (int b = 0; b < M; b++)
                    {
                        if (mapCopy[a][b] == 0)
                        {
                            cnt++;
                        }
                    }
                }
                maxCnt = max(maxCnt, cnt);
            }
        }
    }

    cout << maxCnt;
}
