#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int MOD = 1e9 +7;
int main()
{
    faster()
    test()
    {
        int n, k; cin >> n >> k;
        int a[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        ll dp[k + 5] = {};
        dp[0] = 1;
        for(int i = 1; i <= k;i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i - a[j] >= 0)
                {
                    dp[i] += dp[i - a[j]];
                    dp[i] %= MOD;
                }
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}