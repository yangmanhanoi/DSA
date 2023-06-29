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
int n, m;
int visited[1005] = {};
void dfs(vector<int> Ke[], int u)
{
    visited[u] = 1;
    for (auto &x : Ke[u])
    {
        if (!visited[x])
        {
            dfs(Ke, x);
        }
    }
}
int main()
{
    faster()
        test()
    {
        cin >> n >> m;
        memset(visited, 0, sizeof(visited));
        vector<int> Ke[n + 5], Kex[n + 5];
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            Ke[x].push_back(y);
            Kex[y].push_back(x);
        }
        int check = 1;
        dfs(Ke, 1);
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                check = 0;
                break;
            }
        }
        if (!check)
            cout << "NO\n";
        else
        {
            memset(visited, 0, sizeof(visited));
            dfs(Kex, 1);
            for (int i = 1; i <= n; i++)
            {
                if (!visited[i])
                {
                    check = 0;
                    break;
                }
            }
            if(!check) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}