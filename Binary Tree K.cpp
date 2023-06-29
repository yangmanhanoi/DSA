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
    Node* left;
    Node* right;
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
int cnt = 0;
void countLeaf(node root)
{
    if(root->left == nullptr and root->right == nullptr)
    {
        cnt++;
        return;
    }
    if(root->left) countLeaf(root->left);
    if(root->right) countLeaf(root->right);
}
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int m = n;
        int x; cin >> x;
        node root = new Node(x);
        while(--n)
        {
            cin >> x;
            buildTree(root, x);
        }
        countLeaf(root);
        cout << m - cnt << endl;
        cnt = 0;
    }
    return 0;
}