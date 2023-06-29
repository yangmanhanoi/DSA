#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    // faster()
    // test()
    // {
    //     int n, v; cin >> n >> v;
    //     int dp[n][v];
    //     for(int i = 1; i <= n; i++)
    //     {
    //         for(int j = 1; j <= v; j++) dp[i][j] = 0;
    //     }
    //     int w[n], x[n];
    //     for(int i = 1; i <= n; i++)
    //     {
    //         cin >> w[i] >> x[i];
    //     }
    //     int ans = 0;
    //     for(int i = 1; i <= n; i++)
    //     {
    //         for(int j = 1; j <= v; j++)
    //         {
    //             if(j >= w[i])
    //             {
    //                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + x[i]);
    //             }
    //             else
    //             {
    //                 dp[i][j] = dp[i - 1][j];
    //             }
    //             ans = max(ans, dp[i][j]);
    //         }   
    //     }
    //     cout << ans << endl;
    // }
    // return 0;
    faster()
    test()
    {
        int n, v; cin >> n >> v;
        int dp[v + 5] = {};
        int w[n + 5], x[n + 5];
        for(int i = 1; i <= n; i++)
        {
            cin >> w[i] >> x[i];
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = v; j >= w[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + x[i]);
            }
        }
        cout << dp[v] << endl;
    }
    return 0;
}