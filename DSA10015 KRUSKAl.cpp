#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
struct canh
{
    int x, y, w;
};
int n, m;
int root[105], Size[105];
void makeSet()
{
    for(int i = 1; i <= n; i++)
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
bool cmp(canh a, canh b)
{
    return a.w < b.w;
}
inline bool Union(int x, int y)
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
        cin >> n >> m;
        makeSet();
        vector<canh> vs;
        while(m--)
        {
            int x, y, w;
            cin >> x >> y >> w;
            vs.push_back({x, y, w});
        }
        sort(vs.begin(), vs.end(), cmp);
        vector<canh> mst;
        int d = 0;
        for(auto &i : vs)
        {
            if(Union(i.x, i.y))
            {
                mst.push_back(i);
                d += i.w;
            }
        }
        cout << d << endl;
    }
    return 0;
}