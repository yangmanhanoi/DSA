#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m, u,v;
bool bfs(vector<int> Ke[], int i)
{
    int visited[1005] = {};
    visited[i] = 1;
    queue<int> q;
    visited[u] = 1;
    q.push(u);
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(auto &x : Ke[top])
        {
            if(!visited[x])
            {
                if(x == v) return 1;
                q.push(x);
                visited[x] = 1;
            }
        }
    }
    return 0;
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m >> u >> v;
        vector<int> Ke[n + 5];
        while(m--)
        {
            int x, y; cin >> x >> y;
            Ke[x].push_back(y);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i == u or i == v) continue;
            else ans += !bfs(Ke, i);
        }
        cout << ans << endl;
    }
    return 0;
}