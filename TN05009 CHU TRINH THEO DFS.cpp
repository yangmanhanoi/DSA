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
int check = 0;
int n, m, res;
bitset<1005> bs;
int par[1005] = {}, trace[1005] = {};
void dfs(vector<int> Ke[], int u)
{
    if(check) return;
    bs[u] = 1;
    for (auto &x : Ke[u])
    {
        if (x != par[u])
        {
            if (!bs[x])
            {
                par[x] = u;
                trace[x] = u;
                dfs(Ke, x);
            }
            else
            {
                if(x == 1)
                {
                    check = 1;
                    res = u;
                    return;
                }
            }
        }
    }
}
vector<int> vs;
void findPath(int v)
{
    vs.push_back(v);
    int tmp = v;
    while(tmp != 1)
    {
        vs.push_back(trace[tmp]);
        tmp = trace[tmp];
    }
}
int main()
{
    faster()
        test()
    {
        cin >> n >> m;
        vector<int> Ke[n + 5];
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        for(int i = 1; i <= n; i++)
        {
            sort(Ke[i].begin(), Ke[i].end());
        }
        dfs(Ke, 1);
        if(check)
        {
            findPath(res);
            for(int i = vs.size() - 1; i >= 0; i--) cout << vs[i] << ' ';
            cout << 1 << endl;
        }
        else cout << "NO\n";
        bs.reset();
        memset(par, 0, sizeof(par));
        memset(trace, 0, sizeof(trace));
        vs.clear();
        check = 0;
    }
    return 0;
}