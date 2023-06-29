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
        ll a[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        ll dp[n + 5] = {};
        dp[0] = 0; dp[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }
        cout << dp[n] << endl;
    }
    return 0;
}