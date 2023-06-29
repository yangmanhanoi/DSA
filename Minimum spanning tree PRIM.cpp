	#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int w[1005], visited[1005];
vector<pair<int,int>> Ke[1005];
int n, m;
int Prim(int u)
{
    int ans = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
    q.push({0, u});
    w[u] = 0;
//    visited[u] = 1;
    while(!q.empty())
    {
        pair<int,int> top = q.top(); q.pop();
        for(auto &i : Ke[top.second])
        {
            if(!visited[i.first])
            {
                if(i.second < w[i.first])
                {
                    q.push({i.second, i.first});
                    w[i.first] = i.second;
                }
            }
        }
        visited[top.second] = 1;
    }
    for(int i = 1; i <= n; i++) ans += w[i];
    return ans;
}
int main()
{
    faster();
    test()
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            w[i] = 1e9;
            visited[i] = 0;
            Ke[i].clear();
        }
        while(m--)
        {
            int x, y, w; cin >> x >> y >> w;
            Ke[x].push_back({y,w});
            Ke[y].push_back({x, w});
        }
        cout << Prim(1) << endl;
    }
    return 0;
}
