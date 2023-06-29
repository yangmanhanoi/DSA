#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int root[1005], Size[1005];
struct canh
{
    ll x, y, z;
};
void makeSet()
{
    for(int i = 0; i < n; i++)
    {
        root[i] = i;
        Size[i] = 1;
    }
}
int findRoot(int u)
{
    if(u == root[u]) return u;
    else root[u] = findRoot(root[u]);
}
int Union(int x, int y)
{
    x = findRoot(x), y = findRoot(y);
    if(x == y) return 0;
    if (x < y) swap(x, y);
    root[y] = root[x];
    Size[x] += Size[y];
    return 1;
}
bool cmp(canh a, canh b)
{
    return a.z < b.z;
}
int main()
{
    faster();
    cin >> n >> m;
    vector<canh> vs;
    while(m--)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        vs.push_back({x,y,w});
    }
    int f[1005] = {};
    vector<canh> res;
    test()
    {
        int n, m;
        cin >> n >> m;
        f[n] = f[m] = 1;
        for(auto &i : vs)
        {
            if(f[i.y])
            {
                i.z = 1e10;
            }
        }
        ll d = 0;
        sort(vs.begin(),vs.end(), cmp);
        makeSet();
        for(auto &i : vs)
        {
            if(Union(i.x, i.y))
            {
                d += i.z;
            }
        }
        cout << d << endl;
    }
    return 0;
}