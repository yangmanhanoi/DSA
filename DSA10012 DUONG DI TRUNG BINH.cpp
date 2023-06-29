#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        vector<int> Ke[n + 5];
        int dist[105][105];
        for(int i = 1; i <= 100; i ++)
        {
            for(int j = 1; j <= 100; j++)
            {
                dist[i][j] = 1e9;
                dist[i][i] = 0;
            }
        }
        while(m--)
        {
            int x, y; cin >> x >> y;
            dist[x][y] = 1;
        }
        int cnt = 0, sum = 0;
        for(int k = 1; k <= n; k++)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                //cout << dist[i][j] << ' ';
                if(dist[i][j] != 1e9 and dist[i][j] != 0)
                {
                    cnt++;
                    sum += dist[i][j];
                }
            }
            //cout << endl;
        }
        //cout << sum << ' ' << cnt << endl;
        cout << fixed << setprecision(2) << (double)sum / cnt << endl;
    }
    return 0;
}