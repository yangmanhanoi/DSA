#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster();
    test()
    {
        int n; cin >> n;
        ll dp[n + 5];
        dp[0] = dp[1] = 1; dp[2] = 2;
        for(int i = 3; i <= n; i++) dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        cout << dp[n] << "\n";
    }
    return 0;
}