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
void print(node root)
{
    if(root)
    {
        if(root->left) print(root->left);
        if(root->right) print(root->right);
        if(root) cout << root->val << ' ';
    }
}
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int a[n + 5];
        int x; cin >> x;
        node root = new Node(x);
        while(--n)
        {
            cin >> x;
            buildTree(root, x);
        }
        print(root);
        cout << endl;
    }
    return 0;
}