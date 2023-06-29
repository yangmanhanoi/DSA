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
unordered_map<int, node> mp;
int par, child;
char c;
int n;
// Thay vì duyệt từng node để tìm ra root->val == par thì ta có unordered_map vì các par là khác nhau
// Chỉ khi các giá trị khác nhau mới được dùng unorodered_map
// Độ phức tạp khi sử dụng đệ quy O(n^2)
void buildTree(node &root)
{
    cin >> par >> child >> c;
    root = new Node(par);
    mp[par] = root;
    if(c == 'L')
    {
        mp[par]->left = new Node(child);
        mp[child] = mp[par]->left;
    }
    else
    {
        mp[par]->right = new Node(child);
        mp[child] = mp[par]->right;
    }
    while(--n)
    {
        cin >> par >> child >> c;
        if(c == 'L')
        {
            mp[par]->left = new Node(child);
            mp[child] = mp[par]->left;
        }
        else
        {
            mp[par]->right = new Node(child);
            mp[child] = mp[par]->right;
        }
    }
}
void bfs(node root)
{
    queue<node> q;
    q.push(root);
    while(!q.empty())
    {
        node top = q.front();
        cout << top->val << ' ';
        q.pop();
        if(top->left) q.push(top->left);
        if(top->right) q.push(top->right);
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        node root = new Node(par);
        buildTree(root);
        bfs(root);
        cout << endl;
    }
    return 0;
}