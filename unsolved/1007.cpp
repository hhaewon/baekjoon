#include <iostream>
#include <vector>

using namespace std;

int solve(int N, vector<pair<int, int>> &points)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <)
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<pair<int, int>> points;
        for (int j = 0; j < N; j++)
        {
            int a, b;
            cin >> a >> b;
            points.push_back({a, b});
        }
        cout << solve(N, points);
    }
}