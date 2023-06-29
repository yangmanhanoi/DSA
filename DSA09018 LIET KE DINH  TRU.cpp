#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int low[1005] = {}, num[1005] = {}, par[1005] = {}, visited[1005] = {}, cnt = 1;
set<int> s;
void dfs(vector<int> Ke[], int u)
{
    int cntChild = 0;
    visited[u] = 1;
    low[u] = num[u] = cnt++;
    for(auto &x : Ke[u])
    {
        if(par[u] != x)
        {
            if(!visited[x])
            {
                cntChild++;
                visited[x] = 1;
                par[x] = u;
                dfs(Ke, x);
                low[u] = min(low[u], low[x]);
                if(low[x] >= num[u] and par[u] != 0) s.insert(u);
            }else low[u] = min(low[u], num[x]);
        }
    }
    if(cntChild > 1 and par[u] == 0) s.insert(u);
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
        dfs(Ke, 1);
        for(auto &i : s) cout << i << ' ';
        cout << endl;
        memset(visited, 0, sizeof(visited));
        memset(low, 0, sizeof(low));
        memset(num , 0, sizeof(num));
        memset(par, 0, sizeof(par));
        s.clear();
        cnt = 1;
    }
}