#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int color[1005] = {}, visited[1005] = {};
bool bfs(vector<int> Ke[], int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(auto &x : Ke[top])
        {
            if(!visited[x])
            {
                if(color[top] == 0) color[x] = 1;
                else if(color[top] == 1) color[x] = 0;
                visited[x] = 1;
                q.push(x);
            }
            else
            {
                if(color[x] == color[top]) return 0;
            }
        }
    }
    return 1;
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        vector<int> Ke[n + 5];
        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));
        while(m--)
        {
            int x, y; cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        int check = 1;
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                if(!bfs(Ke, i))
                {
                    check = 0;
                    break;
                }
            }
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}