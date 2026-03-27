#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
    int value;
    int parent;
    vector<int> children;
} Node;

int N, R, Q;
vector<int> edges[100001];
Node *nodes[100001];
int subTreeCnt[100001];

void makeTree(int node)
{
    for (int i = 0; i < edges[node].size(); i++)
    {
        if (nodes[node]->parent)
        {
            continue;
        }
        nodes[node]->children.push_back(edges[node][i]);
        nodes[node]->parent = node;
        makeTree(edges[node][i]);
    }
}

void fillSubTreeCnt(int node)
{
    subTreeCnt[node] = 1;
    for (int i = 0; i < nodes[node]->children.size(); i++)
    {
        fillSubTreeCnt(nodes[node]->children[i]);
        subTreeCnt[node] += subTreeCnt[nodes[node]->children[i]];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> Q;
    for (int i = 1; i <= N; i++)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->value = i;
        nodes[i] = temp;
    }
    nodes[R]->parent = -1;
    for (int i = 0; i < N - 1; i++)
    {
        int first, second;
        cin >> first >> second;
        edges[first].push_back(second);
        edges[second].push_back(first);
    }

    makeTree(R);
    fillSubTreeCnt(R);

    for (int i = 0; i < Q; i++)
    {
        int u;
        cin >> u;
        cout << subTreeCnt[u] << "\n";
    }
}