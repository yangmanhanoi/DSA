#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() \
    int t = 1; \
    cin >> t;  \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
int root[1005], Size[1005];
int n, m;
void makeSet()
{
    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
       // Size[i] = 1;
    }
}
int findRoot(int u)
{
    if (u == root[u])
        return u;
    return root[u] = findRoot(root[u]);
}
int Union(int x, int y)
{
    int rootX = findRoot(x), rootY = findRoot(y);
    if (rootX != rootY)
    {
        // if (Size[rootX] < Size[rootY])
        //     swap(rootX, rootY);
        // root[rootY] = rootX;
        // Size[rootX] += Size[rootY];
        root[rootY] = rootX;
    }
}
int main()
{
    faster();
    test()
    {
        cin >> n >> m;
        makeSet();
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }
        set<int> s;
        for(int i = 1; i <= n; i++)
        {
            s.insert(findRoot(i));
        }
        cout <<  s.size() << endl;
    }
    return 0;
}