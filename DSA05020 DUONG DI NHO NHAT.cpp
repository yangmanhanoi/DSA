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
        int n, m; cin >> n >> m;
        int a[n + 5][m + 5], dp[n + 5][m + 5];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++) cin >> a[i][j];
        }
        dp[1][1] = a[1][1];
        for(int i = 2; i <= m; i++) dp[1][i] = dp[1][i - 1] + a[1][i];
        for(int i = 2; i <= n; i++) dp[i][1] = dp[i - 1][1] + a[i][1];
        for(int i = 2; i <= n; i++)
        {
            for(int j = 2; j <= m; j++)
            {
                dp[i][j] = min({dp[i - 1][j] + a[i][j], dp[i - 1][j - 1] + a[i][j], dp[i][j - 1] + a[i][j]});
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}