#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<pair<int, int>> dq;
int N;
int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        dq.push_back({i, temp});
    }
    int size = N;
    int rotateNum = 0;
    for (int i = 0; i < N; i++)
    {
        pair<int, int> temp;
        if (rotateNum >= 0)
        {
            for (int j = 0; j < rotateNum - 1; j++)
            {
                temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
            cout << dq.front().first << " ";
            rotateNum = dq.front().second;
            dq.pop_front();
            size--;
        }
        else
        {
            while (size + rotateNum < 0)
            {
                rotateNum += size;
            }
            for (int j = 0; j < size + rotateNum; j++)
            {
                temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
            cout << dq.front().first << " ";
            rotateNum = dq.front().second;
            dq.pop_front();
            size--;
        }
    }
}