#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m, u;
int visited[1005] = {};
int trace[1005] = {};
void bfs(vector<int> Ke[])
{
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int top = q.front();
        visited[top] = 1;
        q.pop();
        for(auto &x : Ke[top])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = 1;
                trace[x] = top;
            }
        }
    }
}
void findPath(int v)
{
    if(trace[v] == 0) cout << "No path";
    else
    {
        int tmp = v;
        vector<int> vs;
        vs.push_back(v);
        while(tmp != u)
        {
            vs.push_back(trace[tmp]);
            tmp = trace[tmp];
            if(tmp == 0)
            {
                cout << "No path";
                return;
            }
        }
        for(int i = vs.size() - 1; i >= 0; i--) cout << vs[i] << ' ';
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m >> u;
        vector<int> Ke[n + 5];
        while(m--)
        {
            int x, y;
            cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        bfs(Ke);
        for(int i = 1; i <= n; i++)
        {
            if(i == u) continue;
            else
            {
                findPath(i);
                cout << endl;
            }
        }
        memset(visited, 0, sizeof(visited));
        memset(trace, 0, sizeof(trace));
    }
    return 0;
}