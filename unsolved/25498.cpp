#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    char value;
    int key;
    vector<Node *> children;
};

Node *nodes[500001];
string result = "";

vector<int> edges[500001];
bool visited1[500001];
bool visited2[500001];

void buildTree(int node)
{
    for (auto &e : edges[node])
    {
        if (!visited1[e])
        {
            nodes[node]->children.push_back(nodes[e]);
            visited1[e] = true;
            buildTree(e);
        }
    }
}

void bfs()
{
    pair<
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string chars;
    cin >> N;
    cin >> chars;

    for (int i = 0; i < N; i++)
    {
        Node *tempNode = new Node;
        tempNode->value = chars[i];
        tempNode->key = i + 1;
        nodes[i + 1] = tempNode;
    }

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    visited1[1] = true;
    buildTree(1);
    string result = "";
    result += nodes[1]->value;
    bfs();
    cout << result;
}