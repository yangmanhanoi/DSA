#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
bool dfs(vector<int> Ke[], int u, int v)
{
    int visited[n + 5] = {};
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        visited[top] = 1;
        for(auto &x : Ke[top])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = 1;
                if(x == v) return 1;
            }
        }
    }
    return 0;
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        vector<int> Ke[n + 5];
        while(m--)
        {
            int x, y; cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        int q; cin >> q;
        while(q--)
        {
            int u, v; cin >> u >> v;
            if(dfs(Ke, u, v)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}