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
void buildTree(node root, int par, int child, char c)
{
    if(root->val == par)
    {
        if(c == 'L') root->left = new Node(child);
        else root->right = new Node(child);
    }
    if(root->left) buildTree(root->left, par, child, c);
    if(root->right) buildTree(root->right, par, child, c);
}
void inOrder(node root)
{
    if(root)
    {
        if(root->left) inOrder(root->left);
        if(root) cout << root->val << ' ';
        if(root->right) inOrder(root->right);
    }
}
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int par, child;
        char c;
        cin >> par >> child >> c;
        node root = new Node(par);
        buildTree(root, par, child, c);
        while(--n)
        {
            cin >> par >> child >> c;
            buildTree(root, par, child, c);
        }
        inOrder(root);
        cout << endl;
    }
    return 0;
}