#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    pair<int, int> arr[50000];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    double maxSlope = -1;
    pair<int, int> maxPair;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double slope = abs(((double)arr[i].second - (double)arr[j].second) / ((double)arr[i].first - (double)arr[j].first));
            if (slope > maxSlope)
            {
                maxPair.first = i;
                maxPair.second = j;
                maxSlope = slope;
            }
            else if (slope == maxSlope)
            {
                if (maxPair.first > i)
                {
                    maxPair.first = i;
                    maxPair.second = j;
                    maxSlope = slope;
                }
                else if (maxPair.first == i && maxPair.second > j)
                {

                    maxPair.first = i;
                    maxPair.second = j;
                    maxSlope = slope;
                }
            }
        }
    }

    cout << maxPair.first + 1 << " " << maxPair.second + 1;
}