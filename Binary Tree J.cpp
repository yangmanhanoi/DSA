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
        this->left = nullptr;
        this->right = nullptr;
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
    if (root->val <= val)
        buildTree(root->right, val);
    else
        buildTree(root->left, val);
}
set<int> s;
void print(node root)
{
        if (!root->left and !root->right)
        {
            s.insert(root->val);
            return;
        }
        if (root->left)
            print(root->left);
        if (root->right)
            print(root->right);
}
int main()
{
    faster()
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
        print(root);
        for(auto &i : s) cout << i << ' ';
        cout << endl;
        s.clear();
    }
    return 0;
}