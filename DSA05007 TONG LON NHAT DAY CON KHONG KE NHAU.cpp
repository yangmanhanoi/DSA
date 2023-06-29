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
        int dp[n + 5];
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[i] = a[i];
        }
        dp[0] = 0;
        for(int i = 2; i <=n; i++)
        {
            dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
        }
        cout << dp[n] << endl;
    }
    return 0;
}