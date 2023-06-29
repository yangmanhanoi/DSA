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
int a[1005];
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
void buildTree(node &root, int l, int r)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    root = new Node(a[mid]);
    buildTree(root->left, l, mid - 1);
    buildTree(root->right, mid + 1, r);
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
    faster()
    test()
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        // Khởi tạo node root bằng null trước khi buildTree
        node root = nullptr;
        buildTree(root, 1, n);
        Preorder(root);
        cout << endl;
    }
    return 0;
}