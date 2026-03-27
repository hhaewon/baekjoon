#include <iostream>
using namespace std;

int A[11];
int N;
int op[4]; // +, -, *, /

int usedOp[4];

int maxVal = -1e9;
int minVal = +1e9;
int val = 0;

// index : 0~N-1
void go(int index)
{
    if (index == N)
    {
        if (val > maxVal)
        {
            maxVal = val;
        }
        if (val < minVal)
        {
            minVal = val;
        }
        return;
    }
    int temp = val;
    if (usedOp[0] < op[0])
    {
        usedOp[0]++;
        val = val + A[index];
        go(index + 1);
        usedOp[0]--;
        val = temp;
    }
    if (usedOp[1] < op[1])
    {
        usedOp[1]++;
        val = val - A[index];
        go(index + 1);
        usedOp[1]--;
        val = temp;
    }
    if (usedOp[2] < op[2])
    {
        usedOp[2]++;
        val = val * A[index];
        go(index + 1);
        usedOp[2]--;
        val = temp;
    }
    if (usedOp[3] < op[3])
    {
        usedOp[3]++;
        val = val / A[index];
        go(index + 1);
        usedOp[3]--;
        val = temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }
    val = A[0];
    go(1);
    cout << maxVal << "\n";
    cout << minVal;
}