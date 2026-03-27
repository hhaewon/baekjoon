#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[50][50];
vector<pair<int, int>> house;   // y, x
vector<pair<int, int>> chicken; // y, x
int shouses[50];
int totalresult = -1;

void backtracking(int prev, int index)
{
    if (index == M)
    {
        int result = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int temp = abs(house[i].first - chicken[shouses[0]].first) + abs(house[i].second - chicken[shouses[0]].second);
            for (int j = 1; j < M; j++)
            {
                temp = min(temp, abs(house[i].first - chicken[shouses[j]].first) + abs(house[i].second - chicken[shouses[j]].second));
            }
            result += temp;
        }

        if (totalresult == -1 || totalresult > result)
        {
            totalresult = result;
        }
        return;
    }
    for (int i = prev + 1; i < chicken.size(); i++)
    {
        shouses[index] = i;
        backtracking(i, index + 1);
    }
}

void solve()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                chicken.push_back({i, j});
            }
            else if (arr[i][j] == 1)
            {
                house.push_back({i, j});
            }
        }
    }

    backtracking(-1, 0);
    cout << totalresult;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    solve();
}