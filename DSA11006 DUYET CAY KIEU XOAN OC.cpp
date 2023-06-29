#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
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
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
};
typedef Node* node;
unordered_map<int, node> mp;
int par, child;
char c;
int n;
int trace[10005] = {};
void buildTree(node &root)
{
    cin >> par >> child >> c;
    root = new Node(par);
    mp[par] = root;
    if (c == 'L')
    {
        mp[par]->left = new Node(child);
        mp[child] = mp[par]->left;
    }
    else
    {
        mp[par]->right = new Node(child);
        mp[child] = mp[par]->right;
    }
    while (--n)
    {
        cin >> par >> child >> c;
        if (c == 'L')
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
vector<int> vs;
void bfs(node root)
{
    queue<node> q;
    q.push(root);
    while(!q.empty())
    {
        node top = q.front();
        vs.push_back(top->val);
        q.pop();
        if(top->left)
        {
            q.push(top->left);
            trace[top->left->val] = trace[top->val] + 1;
        }
        if(top->right)
        {
            q.push(top->right);
            trace[top->right->val] = trace[top->val] + 1;
        }
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
        for(int i = 0; i < vs.size(); i++)
        {
            if(trace[vs[i]] % 2 != 0) cout << vs[i] << ' ';
            else
            {
                vector<int> v;
                while(i < vs.size() and trace[vs[i]] % 2 == 0)
                {
                    v.push_back(vs[i]);
                    i++;
                }
                for(int j = v.size() - 1; j >= 0; j--) cout << v[j] << ' ';
                i--;
            }
        }
        cout << endl;
        memset(trace, 0, sizeof(trace));
        vs.clear();
        mp.clear();
    }
    return 0;
}