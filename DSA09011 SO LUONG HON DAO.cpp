#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int a[505][505];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int visited[505][505] ={};
void dfs(int i, int j)
{
    visited[i][j] = 1;
    for(int k = 0; k < 8; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 0 and i1 < n and j1 >= 0 and j1 < m and a[i1][j1] == 1 and !visited[i1][j1])
        {
            dfs(i1, j1);
        }
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                visited[i][j] = 0;
            }
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] and !visited[i][j])
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}