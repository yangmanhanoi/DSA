#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
int n, m, u;
void Try(vector<int> Ke[], int u, bitset<1005> &bs, vector<pair<int, int>> &vs)
{
    bs[u] = 1;
    for(auto &x : Ke[u])
    {
        if(!bs[x])
        {
            vs.push_back({u, x});
            Try(Ke, x, bs, vs);
        }
    }
}
int main()
{
    faster()
        test()
    {
        cin >> n >> m >> u;
        vector<int> Ke[n + 5];
        bitset<1005> bs;
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        vector<pair<int,int>> vs;
        Try(Ke, u, bs, vs);
        if(vs.size() == n - 1)
        {
            for(auto &i : vs) cout << i.first << ' ' << i.second << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}