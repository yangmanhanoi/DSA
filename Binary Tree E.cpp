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
bool bfs(node root)
{
    queue<node> q;
    q.push(root);
    while(!q.empty())
    {
        int cnt = 0;
        node top = q.front();
        q.pop();
      //  vs.push_back(top->val);
        if(top->right)
        {
            q.push(top->right);
            trace[top->right->val] = trace[top->val] + 1;
            cnt++;
        }
        if(top->left)
        {
            q.push(top->left);
            trace[top->left->val] = trace[top->val] + 1;
            cnt++;
        }
    //    if(trace[top->val] == 0) continue;
        if(top->left == nullptr and top->right == nullptr)
        {
            // s.insert(trace[top->val]);
            // if(s.size() > 1) return 0;
            continue;
        }
        if(cnt != 2) return 0;
    }
    return 1;
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        node root = new Node(par);
        buildTree(root);
       // cout << bfs(root) << endl;
        if(bfs(root)) cout << "Yes\n";
        else cout << "No\n";
        mp.clear();
        s.clear();
        memset(trace, 0, sizeof(trace));
    }
    return 0;
}