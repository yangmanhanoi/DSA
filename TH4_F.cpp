#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
set<int> s;
vector<pair<int,int>> vs;
int num[10005] = {}, low[10005] = {}, cnt = 1, visited[100005] = {}, par[100005] = {};
void dfs(vector<int> Ke[], int u)
{
    visited[u] = 1;
    num[u] = low[u] = cnt++;
    int cntChild = 0;
    for(auto &x : Ke[u])
    {
        if(x != par[u])
        {
            if(!visited[x])
            {
                cntChild++;
                par[x] = u;
                dfs(Ke, x);
                low[u] = min(low[u], low[x]);
                if(low[x] >= num[u] and par[u] != 0) s.insert(u);
                if(low[x] == num[x]) vs.push_back({u, x});
            }
            else low[u] = min(low[u], num[x]);
        }
    }
    if(cntChild > 1 and par[u] == 0) s.insert(u);
}
int main()
{
    faster()
    cin >> n >>m;
    memset(visited, 0, sizeof(visited));
    memset(par, 0, sizeof(par));
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    vector<int> Ke[n + 5];
    while(m--)
    {
        int x, y; cin >> x >> y;
        Ke[x].push_back(y);
        Ke[y].push_back(x);
    }
    dfs(Ke, 1);
    vector<int> v;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            v.push_back(i);
        }
    }
    for(auto &i : v) dfs(Ke, i);
    cout << s.size() << ' ' << vs.size() << endl;
    s.clear();
    vs.clear();
}