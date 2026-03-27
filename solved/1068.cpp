#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int key;
    vector<Node> children;
};

bool visited[51];
int N;
int K;
int cnt = 0;
vector<Node> nodes;
Node rootNode;

void buildTree(int i)
{
    // cout << "dfs : " << i << ", children's size : " << nodes[i].children.size() << "\n";
    visited[i] = true;
    if (i == K)
    {
        return;
    }

    if (nodes[i].children.size() == 0 || (nodes[i].children.size() == 1 && nodes[i].children[0].key == K && i != 0))
    {
        cnt++;
        return;
    }

    for (int j = 0; j < nodes[i].children.size(); j++)
    {
        // cout << nodes[i].children[j].key << "\n";
        if (!visited[nodes[i].children[j].key])
        {
            buildTree(nodes[i].children[j].key);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    rootNode.key = 0;
    nodes.push_back(rootNode);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        Node newNode;
        newNode.key = i;
        nodes.push_back(newNode);
    }
    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        nodes[temp + 1].children.push_back(nodes[i]);
    }

    // for (int i = 0; i <= N; i++)
    // {
    //     cout << "Node " << i << "'s children : " << "\n";
    //     for (int j = 0; j < nodes[i].children.size(); j++)
    //     {
    //         cout << nodes[i].children[j].key << " ";
    //     }
    //     cout << "\n";
    // }
    cin >> K;
    K++;

    buildTree(0);
    cout << cnt;
}