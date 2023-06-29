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
        int a[n + 5];
        int dp[n + 5] = {};
        dp[0] = dp[1] = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 2; i <= n; i++)
        {
            if(i == 2) dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
            else dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
           
        }
        cout << dp[n] << endl;
    }
    return 0;
}