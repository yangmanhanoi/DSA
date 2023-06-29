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
        ll sum = -1;
        ll a[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        ll dp[n + 5] = {};
        for(int i = 1; i <= n; i++)
        {
            dp[i] = a[i];
            for(int j = i - 1; j >= 1; j--)
            {
                if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        for(int i = 1; i <= n; i++)
        {
            sum = max(sum, dp[i]);
        }
        cout << sum << endl;
    }
    return 0;
}