// Hành trình cháy phố 
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    int n; cin >> n; 
    int a[20][20];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    ll dp[20][35000];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (1 << n); j++)
        {
            dp[i][j] = 1e9;
        }
    }
    for(int i = 0; i < n; i++)
    {
        dp[i][1 << i] = 0;
    }
    for(int j = 0; j <= (1 << n) - 1; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(dp[i][j] == 1e9) continue;
            for(int v = 0; v < n; v++)
            {
                if((j & (1 << v)) == 0)
                {
                    dp[v][j | (1 << v)] = min(dp[v][j | (1 << (v))], dp[i][j] + a[i][v]);
                }
            }
        }
    }
    ll ans = 1e9;
    for(int i = 0; i < n; i++)
    {
        ans = min(dp[i][(1 << n) - 1], ans);
    }
    cout << ans << endl;
    return 0;
}