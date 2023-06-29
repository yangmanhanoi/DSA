#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const ll MOD = 1e9 + 7;
int main()
{
    faster()
    test()
    {
        ll dp[100005] ={};
        dp[0] = dp[1] = 1;
        int n, k; cin >> n >> k;
        for(int i = 2; i <= n; i++)
        {
            for(int j = i - k; j < i; j++)
            {
                if(j < 0) continue;
                else
                {
                    dp[i] += dp[j];
                }
                dp[i] %= MOD;
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}