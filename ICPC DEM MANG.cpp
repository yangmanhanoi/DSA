#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const ll MOD = 1000000007;
int main()
{
    faster()
    int n, m; cin >> n >> m;
    ll dp[2005][2005];
    ll value[n + 5] = {};
    for(int i = 1; i <= m ; i++)
    {
        dp[1][i] = 1;
    }
    value[1] = m;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(j == 1) dp[i][j] = value[i - 1];
            else
            {
                dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - 1]) % MOD;
            }
            value[i] += dp[i][j];
 //           cout << dp[i][j] << ' ';
        }
        value[i] %= MOD;
        if(value[i] < 0)
        {
            value[i] = MOD + value[i];
        }
    }
    cout << value[n] << endl;
    return 0;
}