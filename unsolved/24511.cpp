#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int N;
int A[100000];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (!A[i])
        {
            dq.push_back(temp);
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        dq.push_front(temp);
    }

    for (int i = 0; i < M; i++)
    {
        cout << dq.back() << " ";
        dq.pop_back();
    }
}