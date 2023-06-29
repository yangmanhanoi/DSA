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
        int n; cin >> n;
        ll dp[1005][1005] = {};
        dp[0][0] = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i + 1][j] = (j * dp[i][j]) % MOD;
                dp[i + 1][j] %= MOD;
                dp[i + 1][j + 1] = dp[i][j] % MOD;
                dp[i + 1][j + 1] %= MOD;
            }
        }
        ll ans = 0;
        for(int j = 1; j <= n; j++)
        {
            ans += dp[n][j] % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}