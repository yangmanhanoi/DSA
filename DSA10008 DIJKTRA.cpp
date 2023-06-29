#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m, u;
vector<pair<int,int>> Ke[1005];
void dijsktra()
{
    vector<ll> dis(105, 1e9);
    dis[u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, u});
    while(!q.empty())
    {
        pair<int, int> top = q.top();
        q.pop();
        int k = top.second;
        int kc = top.first;
        if(kc > dis[k]) continue;
        else
        {
            for(auto &i : Ke[k])
            {
                if(dis[i.first] > dis[k] + i.second)
                {
                    dis[i.first] = dis[k] + i.second;
                    q.push({dis[i.first],i.first});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(dis[i] == 1e9) cout << 0 << ' ';
        else cout << dis[i] << ' ';
    }
}
int main()
{
    faster()
    test()
    {  
        cin >> n >> m >> u;
        while(m--)
        {
            int x, y, w;
            cin >> x >> y >> w;
            Ke[x].push_back({y, w});
            Ke[y].push_back({x, w});
        }
        dijsktra();
        cout << endl;
        for(int i = 1; i <= n; i++)
        {
            Ke[i].clear();
        }
    }
    return 0;
}