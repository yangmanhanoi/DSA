#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
double w[1005], visited[1005], ans = 0;
double Dis(pair<int,int> a, pair<int,int> b)
{
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}
double Prim(int u, vector<pair<int,double>> Ke[])
{
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> q;
    q.push({0, u});
    visited[u] = 1;
    w[u] = 0;
    while (!q.empty())
    {
        pair<double, int> top = q.top(); q.pop();
        for(auto &i : Ke[top.second])
        {
            if(!visited[i.first])
            {
                if(w[i.first] > i.second)
                {
                    w[i.first] = i.second;
                    q.push({w[i.first], i.first});
                }
            }
            visited[top.second] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        ans += w[i];
    }
    return ans;
}
int main()
{
    faster();
    cin >> n >> m;
    for(int i = 0; i <= 1001; i++)
    {
        w[i] = 1e9;
        visited[i] = 0;
    }
    vector<pair<int,int>> vs;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        vs.push_back({x,y});
    }
    vector<pair<int, double>> Ke[1005];
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            double tmp = Dis(vs[i],vs[j]);
            Ke[i].push_back({j, tmp});
            Ke[j].push_back({i, tmp});
        }
    }
    for(int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        Ke[x - 1].push_back({y - 1, 0});
        Ke[y - 1].push_back({x - 1, 0});
    }
    cout << fixed << setprecision(2) << Prim(0, Ke);
    return 0;
}