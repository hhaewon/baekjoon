#include <iostream>
#define MAX 1e9 + 7

using namespace std;

int S[20][20];
int N;
int start;
int link;
int startMan[10];
int linkMan[10];
int nStart;
int nLink;
int minDiff = MAX;

void go(int index)
{
    if (nStart > N / 2 || nLink > N / 2)
    {
        return;
    }
    if (index == N)
    {
        minDiff = min(abs(start - link), minDiff);
        return;
    }
    int preStart = start;
    int preLink = link;
    // start
    for (int i = 0; i < nStart; i++)
    {
        start += S[startMan[i]][index] + S[index][startMan[i]];
    }
    startMan[nStart] = index;
    nStart += 1;
    go(index + 1);
    nStart -= 1;
    start = preStart;

    // link
    for (int i = 0; i < nLink; i++)
    {
        link += S[linkMan[i]][index] + S[index][linkMan[i]];
    }
    linkMan[nLink] = index;
    nLink += 1;
    go(index + 1);
    nLink -= 1;
    link = preLink;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> S[i][j];
        }
    }
    go(0);

    cout << minDiff;
}

// 복기 - 절반씩 가져간다는 조건 빼먹음.