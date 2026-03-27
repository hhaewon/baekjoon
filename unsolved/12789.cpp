#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N;
deque<int> dq;
vector<int> stack;
int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        dq.push_back(temp);
    }

    bool flag = true;
    for (int i = 1; i <= N; i++)
    {
        if (!stack.empty() && stack.back() == i)
        {
            stack.pop_back();
            continue;
        }
        if (dq.empty())
        {
            flag = false;
            break;
        }

        while (!dq.empty() && dq.front() != i)
        {
            stack.push_back(dq.front());
            dq.pop_front();
        }

        if (dq.empty())
        {
            flag = false;
            break;
        }
        dq.pop_front();
    }

    if (flag)
    {
        cout << "Nice";
    }
    else
    {
        cout << "Sad";
    }
}