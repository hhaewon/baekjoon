#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int A[200000];
int B[200001];
int N, K;

void solve()
{
    vector<pair<int, int>> result;
    int cnt = 0;
    int flag = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (B[A[i]] < B[A[j]])
            {
                result.push_back({A[i], A[j]});
                cnt++;

                if (cnt == K)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
        {
            break;
        }
    }

    if (flag)
    {
        cout << "Yes\n";
        for (auto &i : result)
        {
            cout << i.first << " " << i.second << "\n";
        }
    }
    else
    {
        cout << "No";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        B[temp] = i;
    }

    solve();
}