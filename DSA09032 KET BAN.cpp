#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int root[100005] = {}, Size[100005] = {};
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
void Union(int x, int y)
{
    int rootX = findRoot(x);
    int rootY = findRoot(y);
    if(rootX != rootY)
    {
        if(Size[rootX] < Size[rootY]) swap(rootX, rootY);
        root[rootY] = rootX;
        Size[rootX] += Size[rootY];
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        makeSet();
        while(m--)
        {
            int x, y; cin >> x >> y;
            Union(x, y);
        }
        int ans = -1;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, Size[findRoot(i)]);
        }
        cout << ans << endl;
    }
    return 0;
}