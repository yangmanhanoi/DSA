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
        int a[n + 5][m + 5];
        int dp[n + 5][m + 5];
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                dp[i][j] = a[i][j];
            }
        }
        for(int i = 1; i <= n; i++) dp[i][0] = 0;
        for(int i = 1; i <= m; i++) dp[0][i] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i][j])
                {
                    if(!a[i - 1][j] or !a[i - 1][j - 1] or !a[i][j - 1]) continue;
                    dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                    dp[i][j]++;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}