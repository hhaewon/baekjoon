#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

vector<int> tree[MAX_N * 4];
int arr[MAX_N];
int minX = 1000000001;
int maxX = -1000000001;

int n, Q;

void init(int start, int end, int node)
{
    if (start == end)
    {
        tree[node].push_back(arr[start]);
        return;
    }

    int mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    merge(tree[node * 2].begin(), tree[node * 2].end(), tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), back_inserter(tree[node]));
}

int query(int start, int end, int left, int right, int node, int value)
{
    if (start > right || end < left)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return upper_bound(tree[node].begin(), tree[node].end(), value) - tree[node].begin();
    }

    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2, value) + query(mid + 1, end, left, right, node * 2 + 1, value);
}

int Qquery(int i, int j, int k)
{
    int size = j - i + 1;
    int left = minX;
    int right = maxX;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (query(0, n - 1, i, j, 1, mid) < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> n >> Q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        minX = min(minX, arr[i]);
        maxX = max(maxX, arr[i]);
    }
    init(0, n - 1, 1);
    for (int i = 0; i < Q; i++)
    {
        cin >> a >> b >> c;
        cout << Qquery(a - 1, b - 1, c) << '\n';
    }
    return 0;
}