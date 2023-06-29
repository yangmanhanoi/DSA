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
int n;
int visited[1005] = {}, par[1005] = {};
bool bfs(vector<int> Ke[], int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (auto &x : Ke[top])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            return 0;
    }
    return 1;
}
int main()
{
    faster()
        test()
    {
        int k;
        cin >> n; k = n;
        vector<int> Ke[n + 5];
        while (--k)
        {
            int x, y;
            cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        int check = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!bfs(Ke, i))
            {
                check = 0;
                break;
            }
            memset(visited, 0, sizeof(visited));
        }
        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}