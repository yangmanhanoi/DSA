#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->right = nullptr;
        this->left = nullptr;
    }
};
typedef Node *node;
void buildTree(node &root, int val)
{
    if (!root)
    {
        root = new Node(val);
        return;
    }
    if (root->val > val)
        buildTree(root->left, val);
    else
        buildTree(root->right, val);
}
void Preorder(node root)
{
    if (root)
    {
        cout << root->val << ' ';
        if (root->left)
            Preorder(root->left);
        if (root->right)
            Preorder(root->right);
    }
}
int main()
{
    faster();
    test()
    {
        int n;
        cin >> n;
        int x;
        cin >> x;
        node root = new Node(x);
        while (--n)
        {
            cin >> x;
            buildTree(root, x);
        }
        Preorder(root);
        cout << endl;
    }
    return 0;
}