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
int n, k, m;
unordered_map<int, int> mp;
int visited[1005] = {};
int cnt = 1;
vector<int> vs;
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
            cin >>
        k >> n >> m;
    vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    // cout << mp.size() << endl;
    vector<int> Ke1[n + 5];
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        Ke1[x].push_back(y);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int x = 1;
        memset(visited, 0, sizeof(visited));
        dfs(Ke1, i);
        for(auto &j : a)
        {
            if(!visited[j])
            {
                x = 0;
                break;
            }
        }
        ans += x;
    }
    cout << ans << endl;
    return 0;
}