#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int a[505][505];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int ans = 1e9;
void dijkstra()
{
    int visited[505][505] = {};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({a[0][0], {0,0}});
    visited[0][0] = 1;
    while(!pq.empty())
    {
        pair<int, pair<int, int>> top = pq.top();
        pq.pop();
        for(int k = 0; k < 4; k++)
        {
            int i1 = top.second.first + dx[k];
            int j1 = top.second.second + dy[k];
            if(i1 >= 0 and i1 < n and j1 >= 0 and j1 < m and !visited[i1][j1])
            {
                visited[i1][j1] = 1;
                pq.push({top.first + a[i1][j1], {i1, j1}});
                if(i1 == n - 1 and j1 == m - 1)
                {
                    ans = top.first + a[i1][j1];
                }
            }
        }
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) cin >> a[i][j];
        dijkstra();
        cout << ans << endl;
    }
    return 0;
}