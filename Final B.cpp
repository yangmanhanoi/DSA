#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, a[1005];
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
void buildTree(node root, int idx)
{
    if(idx <= n)
    {
        node tmp = new Node(a[idx]);
        root = tmp;
        buildTree(root->left, idx << 1);
        buildTree(root->right, (idx << 1) + 1);
    }
}
void print(int idx)
{
    if(idx <= n)
    {
        if(idx << 1 <= n) print(idx << 1);
        if((idx * 2) + 1 <= n) print((idx * 2) + 1);
        if(idx <= n) cout << a[idx] << ' ';
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        print(1);
        cout << endl;
    }
    return 0;
}