#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int a[105][105];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int cnt = 0;
void Try(int i, int j)
{
    for(int k = 0; k < 2; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 0 and i1 < n and j1 >= 0 and j1 < m)
        {
            if(i1 == n - 1 and j1 == m - 1)
            {
                cnt++;
                return;
            }
            Try(i1, j1);
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
        {
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        Try(0, 0);
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}