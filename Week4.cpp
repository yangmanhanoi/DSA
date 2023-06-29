#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
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
int n;
int par, child;
char c;
typedef Node *node;
// void buildTree(node& root)
// {
//     unordered_map<int, node> mp;
//     cin >> par >> child >> c;
//     root = new Node(par);
//     mp[par] = root;
//     if (c == 'L')
//     {
//         mp[par]->left = new Node(child);
//         mp[child] = mp[par]->left;
//     }
//     else
//     {
//         mp[par]->right = new Node(child);
//         mp[child] = mp[par]->right;
//     }
//     while (--n)
//     {
//         cin >> par >> child >> c;
//         if (c == 'L')
//         {
//             mp[par]->left = new Node(child);
//             mp[child] = mp[par]->left;
//         }
//         else
//         {
//             mp[par]->right = new Node(child);
//             mp[child] = mp[par]->right;
//         }
//     }
// }
void buildTree(node &root)
{
    if (root)
    {
        if (root->val == par)
        {
            if (c == 'L')
            {
                root->left = new Node(child);
            }
            else
                root->right = new Node(child);
            return;
        }
        else
        {
            buildTree(root->left);
            buildTree(root->right);
        }
    }

}
int m;
int dfs(node root)
{
    if (root == nullptr)
        return 0;
    int maxL = dfs(root->left);
    int maxR = dfs(root->right);
    if (root->left == nullptr and root->right == nullptr)
        return root->val;
    if (root->left == nullptr and root->right != nullptr)
        return root->val + maxR;
    if (root->left != nullptr and root->right == nullptr)
        return root->val + maxL;
    m = max(m, root->val + maxR + maxL);
    return max(maxR, maxL) + root->val;
}
int main()
{
    faster()
        test()
    {
        cin >> n;
        cin >> par >> child >> c;
        node root = new Node(par);
        buildTree(root);
        while(--n)
        {
            cin >> par >> child >> c;
            buildTree(root);
        }
        m = -1e9;
        dfs(root);
        cout << m << endl;
    }
    return 0;
}