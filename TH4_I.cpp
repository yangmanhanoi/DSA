#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
int n, m, q;
int st, endd;
vector<pair<ll, ll>> Ke[305];
int par[305] = {};
void dijkstra(int i)
{
    vector<ll> dis(n + 5, -1);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> q;
    //priority_queue<pair<ll, ll>> q;
    q.push({0, i});
    while(!q.empty())
    {
        pair<ll, ll> top = q.top();
        q.pop();
        ll u = top.second;
        ll kc = top.first;
        if(kc < dis[u]) continue;
        for(auto &x : Ke[u])
        {
            if(dis[x.first] == dis[par[x.first]])
            {
                dis[x.first] = 
            }
            if(dis[x.first] < max(dis[u], x.second))
            {
                
                dis[x.first] = max(dis[u], x.second);
                q.push({dis[x.first], x.first});
            }
        }
    }
    if(dis[endd] == -1) cout << -1 << endl;
    else cout << dis[endd] << endl;
}
bool cmp(pair<int,int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    faster()
    // ll dist[305][305];
    // ll a[305][305] = {};
    // for (int i = 1; i <= 300; i++)
    // {
    //     for (int j = 1; j <= 300; j++)
    //     {
    //         dist[i][j] = 1e9;
    //         dist[i][i] = 0;
    //         a[i][j] = 1e9;
    //        // a[i][i] = 0;
    //     }
    // }
    cin >> n >> m >> q;
    while (m--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        Ke[x].push_back({y, w});
        par[y] = x;
        // dist[y][x] = w;
    // }
    // for (int k = 1; k <= n; k++)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int j = 1; j <= n; j++)
    //         {
    //             if (dist[i][j] > dist[i][k] + dist[k][j])
    //             {
    //                 dist[i][j] = dist[i][k] + dist[k][j];
    //             }
    //             if (i != k and k != j and i != j)
    //             {
    //                 ll tmp = max(dist[i][k], dist[k][j]);
    //                 a[i][j] = min(a[i][j], tmp);
    //             }
    //         }
    //     }
    }
    for(int i = 1; i <= n; i++)
    {
        sort(Ke[i].begin(), Ke[i].end(), cmp);
    }
    while (q--)
    {
        cin >> st >> endd;
        dijkstra(st);
    }
    return 0;
}