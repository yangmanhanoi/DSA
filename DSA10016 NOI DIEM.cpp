#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
struct point
{
    double a, b;
};
double distance(point x, point y)
{
    return sqrt((x.a - y.a)*(x.a - y.a) + (x.b - y.b) * (x.b - y.b));
}
int root[105], Size[105];
int n;
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
    else return root[u] = findRoot(root[u]);
}
int Union(int x, int y)
{
    int rootX = findRoot(x), rootY = findRoot(y);
    if(rootX == rootY) return 0;
    if(Size[rootX] < Size[rootY]) swap(rootX, rootY);
    root[rootY] = rootX;
    Size[rootX] += Size[rootY];
    return 1;
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        vector<point> vs;
        for(int i = 0; i < n; i++)
        {
            double x, y; cin >> x >> y;
            vs.push_back({x, y});
        }
        makeSet();
        vector<pair<double, pair<int, int>>> res;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                res.push_back({distance(vs[i], vs[j]), {i, j}});
            }
        }
        sort(res.begin(), res.end());
        double d = 0;
        for(auto &i : res)
        {
            if(Union(i.second.first, i.second.second))
            {
                d += i.first;
            }
        }
        cout << fixed << setprecision(6) << d << endl;
    }
    return 0;
}