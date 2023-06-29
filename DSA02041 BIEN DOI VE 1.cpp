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
        int n; cin >> n;
        int dp[n + 5] = {1000005};
        for(int i = 1; i <= n; i++) dp[i] = (int)1e9;
        dp[n] = 0;
        for(int i = n - 1; i >= 1; i--)
        {
            if(i * 3 <= n)
            {
                dp[i] = min(dp[i], dp[i * 3] + 1);
            }
            if(i * 2 <= n)
            {
                dp[i] = min(dp[i], dp[i * 2] + 1);
            }
            dp[i]= min(dp[i], dp[i + 1] + 1);
           // cout << dp[i] << ' ';
        }
        cout << dp[1] << endl;
    }
    return 0;   
}