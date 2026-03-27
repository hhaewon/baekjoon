#include <iostream>
#include <algorithm>

using namespace std;

int scores[100001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int prevMin[3];
    int prevMax[3];
    int curMin[3];
    int curMax[3];

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> scores[i][0] >> scores[i][1] >> scores[i][2];
    }
    prevMin[0] = scores[1][0];
    prevMin[1] = scores[1][1];
    prevMin[2] = scores[1][2];
    prevMax[0] = scores[1][0];
    prevMax[1] = scores[1][1];
    prevMax[2] = scores[1][2];

    for (int i = 2; i <= N; i++)
    {
        curMax[0] = max(prevMax[0], prevMax[1]) + scores[i][0];

        curMax[1] = max(max(prevMax[0], prevMax[1]), prevMax[2]) + scores[i][1];

        curMax[2] = max(prevMax[1], prevMax[2]) + scores[i][2];
        curMin[0] = min(prevMin[0], prevMin[1]) + scores[i][0];

        curMin[1] = min(min(prevMin[0], prevMin[1]), prevMin[2]) + scores[i][1];

        curMin[2] = min(prevMin[1], prevMin[2]) + scores[i][2];

        prevMin[0] = curMin[0];
        prevMin[1] = curMin[1];
        prevMin[2] = curMin[2];
        prevMax[0] = curMax[0];
        prevMax[1] = curMax[1];
        prevMax[2] = curMax[2];
    }

    int totalMax = max(max(prevMax[0], prevMax[1]), prevMax[2]);
    int totalMin = min(min(prevMin[0], prevMin[1]), prevMin[2]);
    cout << totalMax << " " << totalMin;
}