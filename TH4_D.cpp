#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
vector<int> Ke[200005];
int visited[200005] = {};
void bfs(int a, int b)
{
    visited[a] = 1;
    queue<int> q;
    q.push(a);
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(auto &x : Ke[top])
        {
            if(!visited[x] and x != b)
            {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
}
int count(int b)
{
    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    vector<int> v;
    for(auto &i : Ke[b]) v.push_back(i);
    Ke[b].clear();
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            cnt++;
            bfs(i, b);
        }
    }
    for(auto &i : v) Ke[b].push_back(i);
    return cnt;
}
int main()
{
    faster()
    cin >> n >> m;
    while(m--)
    {
        int x, y; cin >> x >> y;
        Ke[x].push_back(y);
        Ke[y].push_back(x);
    }
    vector<ll> vs;
    for(int i = 1; i <= n; i++)
    {
        cout << count(i) - 1 << endl;
    }
    return 0;
}