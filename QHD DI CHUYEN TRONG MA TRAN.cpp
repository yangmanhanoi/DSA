#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int MOD = 1e9 + 7;
int main()
{
    faster()
    test()
    {
        int n, m; cin >> n >> m;
        ll a[n + 5][m + 5];
        ll dp[n + 5][m + 5];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                dp[i][j] = 0;
            }
        }
        dp[1][1] = dp[0][1] = dp[1][0] = 1;
        for(int i = 2; i <= n; i++)
        {
            if(a[i][1]) dp[i][1] = 0;
            else dp[i][1] = dp[i - 1][1];
        }
        for(int j = 2; j <= m; j++)
        {
            if(a[1][j]) dp[1][j] = 0;
            else dp[1][j] = dp[1][j - 1];
        }
        // for(int i = 1; i <= n; i++)
        // {
        //     for(int j = 1; j <= m; j++) cout << dp[i][j] << ' ';
        //     cout << endl;
        // }
        for(int i = 2; i <= n; i++)
        {
            for(int j = 2; j <= m; j++)
            {
                if(a[i][j]) continue;
                else
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                    dp[i][j] %= MOD;
                }
            }
        }
        cout << dp[n][m];
        cout << endl;
    }
    return 0;
}