#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
vector<pair<ll,ll>> vs;
int n;
ll r;
int root[2005], Size[2005];
ll distance(pair<ll,ll> a, pair<ll,ll> b)
{
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
ll findRoot(int u)
{
    if(u == root[u]) return u;
    else return root[u] = findRoot(root[u]);
}
void Union(int x, int y)
{
    x = findRoot(x); y = findRoot(y);
    if(x != y)
    {
        if(Size[x] < Size[y]) swap(x, y);
        Size[x] += Size[y];
        root[y] = root[x];
    }
    
}
int main()
{
    faster();
    cin >> n >> r;
    ll x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        vs.push_back({x,y});
        root[i] = i;
        Size[i] = 1;
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(distance(vs[i], vs[j]) <= r*r)
            {
                Union(root[i], root[j]);
            }
        }
    }
    unordered_set<int> s;
    for(int i = 0; i < n; i++)
    {
        s.insert(findRoot(i));
    }
    cout << s.size() << endl;
    return 0;
}