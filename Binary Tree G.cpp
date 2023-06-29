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
int par, child;
char c;
int n;
void buildTree(node &root)
{
    unordered_map<int, node> mp;
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
int trace[100005] = {};
set<int> s;
ll bfs(node root)
{
    ll ans = 0;
    queue<node> q;
    q.push(root);
    while(!q.empty())
    {
        node top = q.front();
        q.pop();
        if(top->right)
        {
            q.push(top->right);
            if(top->right->right == nullptr and top->right->left == nullptr) ans += top->right->val;
        }
        if(top->left)
        {
            q.push(top->left);  
        }
    }
    return ans;
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        node root = new Node(par);
        buildTree(root);
        cout << bfs(root) << endl;
        s.clear();
        memset(trace, 0, sizeof(trace));
    }
    return 0;
}