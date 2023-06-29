#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m, u;
int visited[1005] = {}, trace[1005] = {};
vector<pair<int,int>> vs;
void bfs(vector<int> Ke[], int u)
{
    queue<pair<int, int>> q;
    q.push({u, 0});
    visited[u] = 1;
    while(!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        for(auto &x : Ke[top.first])
        {
            if(!visited[x])
            {
                visited[x] = 1;
                vs.push_back({top.first, x});
                if(vs.size() == n - 1) break;
                q.push({x, top.second + 1});
            }
        }
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m >> u;
        vector<int> Ke[n + 5];
        memset(visited, 0, sizeof(visited));
        while(m--)
        {
            int x, y; cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        bfs(Ke, u);
        if(vs.size() == n - 1)
        {
            for(auto &i : vs) cout << i.first << ' ' << i.second << endl;
        }
        else cout << -1 << endl;
        vs.clear();
    }
    return 0;
}