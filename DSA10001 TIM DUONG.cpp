#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
pair<int, int> start, ed;
int visited[505][505] = {}, trace[505][505] = {};
char a[505][505];
bool bfs()
{
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    while(!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        int i = top.first + 1;
        while(i < n and !visited[i][top.second] and (a[i][top.second] == '.' or a[i][top.second] == 'T'))
        {
            visited[i][top.second] = 1;
            trace[i][top.second] = trace[top.first][top.second] + 1;
            q.push({i, top.second});
            if(i == ed.first and top.second == ed.second) return trace[ed.first][ed.second] <= 3;
            ++i;
        }
        i = top.first - 1;
        while(i >= 0 and !visited[i][top.second] and (a[i][top.second] == '.' or a[i][top.second] == 'T'))
        {
            visited[i][top.second] = 1;
            trace[i][top.second] = trace[top.first][top.second] + 1;
            q.push({i, top.second});
            if(i == ed.first and top.second == ed.second) return trace[ed.first][ed.second] <= 3;
            --i;
        }
        i = top.second + 1;
        while(i < m and !visited[top.first][i] and (a[top.first][i] == '.' or a[top.first][i] == 'T'))
        {
            visited[top.first][i] = 1;
            trace[top.first][i] = trace[top.first][top.second] + 1;
            q.push({top.first, i});
            if(top.first == ed.first and i == ed.second) return trace[ed.first][ed.second] <= 3;
            ++i;
        }
        i = top.second - 1;
        while(i >= 0 and !visited[top.first][i] and (a[top.first][i] == '.' or a[top.first][i] == 'T'))
        {
            visited[top.first][i] = 1;
            trace[top.first][i] = trace[top.first][top.second] + 1;
            q.push({top.first, i});
            if(top.first == ed.first and i == ed.second) return trace[ed.first][ed.second] <= 3;
            --i;
        }
    }
    return 0;
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                visited[i][j] = 0;
                trace[i][j] = 0;
                cin >> a[i][j];
                if(a[i][j] == 'S') start = {i, j};
                if(a[i][j] == 'T') ed = {i, j};
            }
        }
        if(bfs()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}