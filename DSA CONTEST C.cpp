#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int w[205], visi;
int Dis(pair<int,int> a, pair<int,int> b)
{
    return abs(a.first - b.first) + (a.second - b.second);
}

int main()
{
    faster();
    int n, d; cin >> n >> d;
    int bonus[205]; bonus[0] = bonus[n - 1] = 0;
    for(int i = 1; i < n - 1; i++)
    {
        int x; cin >> x;
        bonus[i] = x;
    }
    vector<pair<int,int>> vs;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        vs.push_back({x, y});
    }
    vector<pair<int ,int>> res[205];
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int tmp = Dis(vs[i],vs[j]) * d;
            res[i].push_back({j, tmp});
            res[j].push_back({i, tmp});
        }
    }
}