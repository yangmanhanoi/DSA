#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int visited[1005] = {};
void bfs(vector<int> Ke[], int u)
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
                visited[x] = 1;
                q.push(x);
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
        vector<int> Ke[n + 5];
        memset(visited, 0, sizeof(visited));
        while(m--)
        {
            int x, y; cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                bfs(Ke, i);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}