#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
int n;
vector<pair<int, int>> Ke[10005];
int visited[10005] = {};
void solve(int s)
{
    vector<int> d(n + 5, 1e9);
   // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    queue<pair<int,int>> q;
    q.push({0, s});
    visited[s] = 1;
    //d[s] = 0;
    while (!q.empty())
    {
        pair<int,int> top = q.front();
        visited[top.second] = 1;
        q.pop();
        int u = top.second;
        int kc = top.first;
        for (auto &it : Ke[u])
        {
            int v = it.first;
            int w = it.second;
            if (d[v] > min(d[u], w))
            {
                d[v] = min(d[u], w);
                q.push({d[v], v});
            }
        }
    }
    if (d[n] == 1e9)
        cout << -1 << endl;
    else
        cout << d[n] << endl;
}
int main()
{
    faster()
    cin >> n;
    int x, y, w;
    while (cin >> x >> y >> w)
    {
        Ke[x].push_back({y, w});
        Ke[y].push_back({x, w});
    }
    solve(1);
    return 0;
}