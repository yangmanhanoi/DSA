#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int root[1005], Size[1005];
double Dis(pair<int,int> a, pair<int,int> b)
{
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

void makeSet()
{
    for(int i = 0; i < n; i++) root[i] = i;
}
int findRoot(int u)
{
    if(u == root[u]) return u;
    return root[u] = findRoot(root[u]);
}
int Union(int a, int b)
{
    a = findRoot(a);
    b = findRoot(b);
    if(a == b) return 0;
    if(a < b) swap(a, b);
    Size[a] += Size[b];
    root[b] = root[a];
    return 1;
}
int main()
{
    cin >> n >> m;
    vector<pair<int,int>> vs;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        vs.push_back({x, y});
    }
    vector<pair<double, pair<int,int>>> res;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            double temp = Dis(vs[i], vs[j]);
            res.push_back({temp, {i,j}});
        }
    }
    double d = 0;
    for(int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        res.push_back({0, {x - 1, y - 1}});
    }
    sort(res.begin(),res.end());
    makeSet();
    for(auto &i : res)
    {
        if(Union(i.second.second, i.second.first))
        {
            d += i.first;
        }
      //  cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
    }
    cout << fixed << setprecision(2) << d << endl;
    return 0;
}