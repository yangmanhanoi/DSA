#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    ll dist[105][105];
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= 100; j++)
        {
            dist[i][j] = 1e9;
            dist[i][i] = 0;
        }
    }
    int n, m, q; cin >> n >> m >> q;
    while(m--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        dist[x][y] = w;
        // dist[y][x] = w;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    while(q--)
    {
        int x, y; cin >> x >> y;
        if(dist[x][y] == 1e9) cout << -1 << endl;
        else cout << dist[x][y] << endl;
    }
    return 0;
}