#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
struct Node
{
    int val;
    Node* right;
    Node* left;
    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
typedef Node* node;
void buildTree(node &root, int val)
{
    if(!root)
    {
        root = new Node(val);
        return;
    }
    if(root->val > val) buildTree(root->left, val);
    else buildTree(root->right, val);
}
int trace[10005] = {};
int cnt = -1;
void countLevel(node root)
{
    if(root->left == nullptr and root->right == nullptr)
    {
        cnt = max(cnt , trace[root->val]);
    }
    if(root->left)
    {
        trace[root->left->val] = trace[root->val] + 1;
        countLevel(root->left);
    }
    if(root->right)
    {
        trace[root->right->val] = trace[root->val] + 1;
        countLevel(root->right);
    }
}
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int x; cin >> x;
        node root = new Node(x);
        while(--n)
        {
            cin >> x;
            buildTree(root, x);
        }
        countLevel(root);
        cout << cnt << endl;
        cnt = -1;
    }
    return 0;
}