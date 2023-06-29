#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int a[1005][1005], trace[1005][1005] = {};
int m, n;
int bfs(int i, int j)
{
    queue<pair<int,int>> q;
    q.push({i, j});
    while(!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
      //  if(top.first == m and top.second == n) return trace[m][n];
        if(top.first + a[top.first][top.second] <= m and !trace[top.first + a[top.first][top.second]][top.second])
        {
            q.push({top.first + a[top.first][top.second], top.second});
            trace[top.first + a[top.first][top.second]][top.second] = trace[top.first][top.second] + 1;
            if(top.first + a[top.first][top.second] == m and top.second == n) return trace[m][n];
        }
        if(top.second + a[top.first][top.second] <= n and !trace[top.first][top.second + a[top.first][top.second]])
        {
            q.push({top.first, top.second + a[top.first][top.second]});
            trace[top.first][top.second + a[top.first][top.second]] = trace[top.first][top.second] + 1;
            if(top.first == m and top.second + a[top.first][top.second] == n) return trace[m][n];
        }
    }
    return -1;
}
int main()
{
    faster()
    test()
    {
        cin >> m >> n;
        memset(trace, 0, sizeof(trace));
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << bfs(1, 1) << endl;
    }
    return 0;
}