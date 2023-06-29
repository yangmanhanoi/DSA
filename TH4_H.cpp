#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() ll t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll n, m;
ll cnt = 1;
ll res = 1e9;
vector<pair<ll, ll>> Ke[100005];
ll dp[100005] = {};
void dijkstra(ll u)
{
    vector<ll> dis(100005, 1e9);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
    dis[u] = 0;
    dp[u] = 1;
    q.push({0, u});
    while(!q.empty())
    {
        pair<ll, ll> top = q.top();
        q.pop();
        ll k = top.second;
        ll kc = top.first;
        if(kc > dis[k]) continue;
        else
        {
            for(auto &i : Ke[k])
            {
                if(dis[i.first] > dis[k] + i.second)
                {
                    dis[i.first] = dis[k] + i.second;
                    dp[i.first] = dp[k];
                    q.push({dis[i.first], i.first});
                }
                else if(dis[i.first] == dis[k] + i.second)
                {
                    dp[i.first] = (dp[k] + dp[i.first]);
                }
            }
        }
    }
    cout << dis[n] << ' ' << dp[n] << endl;
}
int main()
{
    faster()
    cin >> n >> m;
    while(m--)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        Ke[x].push_back({y, w});
        Ke[y].push_back({x, w});
    }
    dijkstra(1);
    return 0;
}