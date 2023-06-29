#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
pair<int,int> start, finish;
char a[105][105];
int n;
int visited[105][105] = {};
int trace[105][105] = {};
int bfs()
{
    queue<pair<int,int>> q;
    q.push(start);
    while(!q.empty())
    {
        pair<int,int> top = q.front();
        q.pop();
        int i = top.first + 1;
        while(i < n and a[i][top.second] == '.' and visited[i][top.second] == 0)
        {
            visited[i][top.second] = 1;
            trace[i][top.second] = trace[top.first][top.second] + 1;
            q.push({i, top.second});
            if(i == finish.first and top.second == finish.second) return trace[finish.first][finish.second];
            i++;
        }
        i = top.first - 1;
        while(i >= 0 and a[i][top.second] == '.' and visited[i][top.second] == 0)
        {
            visited[i][top.second] = 1;
            trace[i][top.second] = trace[top.first][top.second] + 1;
            q.push({i, top.second});
            if(i == finish.first and top.second == finish.second) return trace[finish.first][finish.second];
            --i;
        }
        i = top.second + 1;
        while(i < n and a[top.first][i] == '.' and visited[top.first][i] == 0)
        {
            visited[top.first][i] = 1;
            trace[top.first][i] = trace[top.first][top.second] + 1;
            q.push({top.first, i});
            if(top.first == finish.first and i == finish.second) return trace[finish.first][finish.second];
            i++;
        }
        i = top.second - 1;
        while(i >= 0 and a[top.first][i] == '.' and visited[top.first][i] == 0)
        {
            visited[top.first][i] = 1;
            trace[top.first][i] = trace[top.first][top.second] + 1;
            q.push({top.first, i});
            if(top.first == finish.first and i == finish.second) return trace[finish.first][finish.second];
            i--;
        }
    }
    return 0;
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        cin >> start.first >> start.second;
        cin >> finish.first >> finish.second;
        memset(visited, 0, sizeof(visited));
        memset(trace, 0, sizeof(trace));
        cout << bfs() << endl;
    }
    return 0;
}