#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int root[1005] = {}, SiZe[1005] = {};
void makeSet()
{
    for(int i = 1; i <= n; i++)
    {
        root[i] = i;
        SiZe[i] = 1;
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
        if(SiZe[rootX] < SiZe[rootY]) swap(rootX, rootY);
        root[rootY] = rootX;
        SiZe[rootX] += SiZe[rootY];
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        int check = 0;
        makeSet();
        while(m--)
        {
            int x, y; cin >> x >> y;
            if(root[y] == root[findRoot(x)])
            {
                check = 1;
            }
            Union(x, y);
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}