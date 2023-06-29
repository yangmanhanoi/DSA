#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int a[1005];
struct Node
{
    int val; Node* left;
    Node* right;
    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
typedef Node* node;
void buildTree(node &root, int l, int r)
{
    if(l > r) return;
    int mid = (l + r) / 2;
    root = new Node(a[mid]);
    buildTree(root->left, l, mid-1);
    buildTree(root->right, mid + 1, r);
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
        for(int i = 1; i <= n; i++) cin >> a[i];
        node root = nullptr;
        buildTree(root, 1, n);
        countLeaf(root);
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}