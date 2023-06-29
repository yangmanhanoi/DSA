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
    test()
    {
        int n,m; cin >> n >> m;
        ll a[n + 5][m + 5];
        ll dp[105][105];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                dp[i][j] = 0;
            }
        }
        if(a[1][1] == -1) cout << -1 << endl;
        else
        {
            dp[1][1] = a[1][1];
            for(int i = 2; i <= m; i++)
            {
                if(a[1][i] == -1)
                {
                    dp[1][i] = -1e9;
                    while(i <= m)
                    {
                        ++i;
                        dp[1][i] = -1e9;
                    }
                }
                else
                {
                    dp[1][i] = dp[1][i - 1] + a[1][i];
                } 
            }
            for(int j = 2; j <= n; j++)
            {
                if(a[j][1] == -1)
                {
                    dp[j][1] = -1e9;
                    while(j <= n)
                    {
                        ++j;
                        dp[j][1] = -1e9;
                    }
                }
                else
                {
                    dp[j][1] = dp[j - 1][1] + a[j][1];
                }
            }
            for(int i = 2; i <= n; i++)
            {
                for(int j = 2; j <= m; j++)
                {
                    if(a[i][j] == -1) dp[i][j] = -1e9;
                    else if(dp[i - 1][j] == -1e9 and dp[i][j - 1] == -1e9) dp[i][j] = -1e9;
                    else dp[i][j] = max(dp[i - 1][j] + a[i][j], dp[i][j - 1] + a[i][j]);
                }
            }
            // for(int i = 1; i <= n; i++)
            // {
            //     for(int j = 1; j <= m; j++) cout << dp[i][j] << ' ';
            //     cout << endl;
            // }
            if(dp[n][m] < 0) cout << -1;
            else cout << dp[n][m];
            cout << endl;
        }  
    }
    return 0;
}