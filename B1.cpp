#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int visited[1005][1005] = {};
char a[1005][1005];
int cnt = 0;
void dfs(int u, int v)
{
    for(int k = 0; k < 4; k++)
    {
        int i = u + dx[k];
        int j = v + dy[k];
        if(i > 0 and i < n and j > 0 and j < m and a[i][j] == '#' and !visited[i][j])
        {
            visited[i][j] = 1;
            dfs(i, j);
        }
    }
}
int main()
{
    faster()
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '#' and !visited[i][j])
            {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}