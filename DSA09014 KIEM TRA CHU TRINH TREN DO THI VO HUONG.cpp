#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int visited[1005] = {}, par[1005] = {};
bool dfs(vector<int> Ke[], int u)
{
    visited[u] = 1;
    for(auto &x : Ke[u])
    {
        if(x != par[u])
        {
            if(!visited[x])
            {
                par[x] = u;
                dfs(Ke, x);
            }
            else return 1;
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
        memset(visited, 0, sizeof(visited));
        memset(par, 0, sizeof(par));
        while(m--)
        {
            int x, y; cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        int check = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                if(dfs(Ke, i))
                {
                    check =1 ;
                    break;
                }
            }
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}