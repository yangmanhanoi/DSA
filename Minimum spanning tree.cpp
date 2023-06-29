#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int root[105], Size[105];
struct canh
{
    int x, y, w;
};
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
    return root[u] = findRoot(root[u]);
}
int Union(int a, int b)
{
    a = findRoot(a); b = findRoot(b);
    if(a == b) return 0;
    if(a < b) swap(a,b);
    root[b] = a;
    Size[a] += Size[b];
    return 1;
}
bool cmp(canh a, canh b)
{
    return a.w < b.w;
}
int main()
{
    faster();
    test()
    {
        int d = 0;
        vector<canh> vs;
        cin >> n >> m;
        makeSet();
        while(m--)
        {
            int x, y, w;
            cin >> x >> y >> w;
            vs.push_back({x, y, w});
        }
        sort(vs.begin(), vs.end(), cmp);
        for(auto &i : vs)
        {
            canh tmp = i;
            if(Union(i.x,i.y))
            {
                d += i.w;
            }
        }
        cout << d << endl;
    }
    return 0;
}