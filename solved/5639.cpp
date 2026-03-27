#include <iostream>
#define MAX 10000
using namespace std;

int tree[4 * MAX];

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }

    Node *insert(Node *root, int value)
    {
        if (root == nullptr)
        {
            return new Node(value);
        }
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }

        return root;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void postOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << "\n";
    }

    void postOrder()
    {
        postOrder(root);
    }
};

void solve()
{
    int x;
    BST bst;
    while (cin >> x)
    {
        bst.insert(x);
    }

    bst.postOrder();
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    solve();
}