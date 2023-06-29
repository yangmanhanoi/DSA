#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int visited[1005] = {};
int bfs(vector<int> Ke[], int u)
{
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int top= q.front();
        q.pop();
        visited[top] = 1;
        for(auto &x : Ke[top])
        {
            if(!visited[x])
            {
                visited[x] = 1;
                q.push(x);
            }
            else if(x == u) return 1;
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
        vector<int> Ke[n + 5];
        while(m--)
        {
            int x, y; cin >> x >> y;
            Ke[x].push_back(y);
        }
        int check = 0;
        for(int i = 1; i <= n; i++)
        {
            memset(visited, 0, sizeof(visited));
            if(bfs(Ke, i))
            {
                check = 1;
                break;
            }
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}