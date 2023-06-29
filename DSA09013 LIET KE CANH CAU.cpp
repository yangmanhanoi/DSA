#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int par[1005] = {}, visited[1005] = {}, low[1005] = {}, num[1005] = {}, cnt = 1;
set<pair<int,int>> s;
void dfs(int u, vector<int> Ke[])
{
    visited[u] = 1;
    num[u] = low[u] = cnt++;
    for(auto &x : Ke[u])
    {
        if(x != par[u])
        {
            if(!visited[x])
            {
                par[x] = u;
                dfs(x, Ke);
                low[u] = min(low[u], low[x]);
                if(num[x] == low[x])
                {
                    if(u > x) s.insert({x, u});
                    else s.insert({u, x});
                }
            }
            else low[u] = min(num[x], low[u]);
        }
    }
}
int main()
{
    faster()
    test()
    {
        int n, m; cin >> n >> m;
        vector<int> Ke[n + 5];
        memset(visited, 0, sizeof(visited));
        memset(low, 0, sizeof(low));
        memset(num, 0, sizeof(num));
        memset(par, 0, sizeof(par));
        while(m--)
        {
            int x, y; cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        dfs(1, Ke);
        for(auto &i : s)
        {
            cout << i.first << ' ' << i.second << ' ';
        }
        cout << endl;
        cnt = 1;
        s.clear();
    }
    return 0;
}