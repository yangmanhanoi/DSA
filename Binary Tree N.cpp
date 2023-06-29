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
        this->left = 0;
        this->right = 0;
    }
};
typedef Node* node;
int a[1005];
void buildTree(node &root, int l, int r)
{
    if(l > r) return;
    int mid = ( l + r)/ 2;
    root = new Node(a[mid]);
    buildTree(root->left, l, mid - 1);
    buildTree(root->right, mid + 1, r);
}
void Postorder(node root)
{
    if(root)
    {
        if(root->left) Postorder(root->left);
        if(root->right) Postorder(root->right);
        if(root) cout << root->val << ' ';
    }
}
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        node root = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        buildTree(root, 1, n);
        Postorder(root);
        cout << endl;
    }
    return 0;
}