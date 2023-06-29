#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int visited[1005] = {}, trace[1005] = {};
int n, m, u, v;
void DFS(vector<int> Ke[], int u)
{
    visited[u] = 1;
   // cout << u << ' ';
    for(auto &x : Ke[u])
    {
        if(!visited[x])
        {
            trace[x] = u;
            DFS(Ke, x);
        }
    }
}
void findPath()
{
    if(trace[v] == 0) cout << -1 << endl;
    else
    {
        int tmp = v;
        vector<int> vs;
        vs.push_back(tmp);
        while(tmp != u)
        {
            vs.push_back(trace[tmp]);
            tmp = trace[tmp];
            if(tmp == 0)
            {
                cout << -1 << endl;
                return;
            }
        }
        for(int i = vs.size() - 1; i >= 0; i--) cout << vs[i] << ' ';
        cout << endl;
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m >> u >> v;
        vector<int> Ke[n + 5];
        while(m--)
        {
            int x, y;
            cin >> x >> y;
            Ke[x].push_back(y);
        }
        memset(visited, 0, sizeof(visited));
        memset(trace, 0, sizeof(trace));
        DFS(Ke, u);
        findPath();
        //cout << endl;
    }
    return 0;
}