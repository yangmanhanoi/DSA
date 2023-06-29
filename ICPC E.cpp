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
    ll n; cin >> n;
    ll a[n + 5];
    vector<pair<ll,ll>> dp;
    ll res_min, res_max;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == 0)
        {
            res_max = a[i];
            res_min = a[i];
        }
        else
        {
            res_max = max(res_max, a[i]);
            res_min = min(res_min, a[i]);
        }
        dp.push_back({res_min,res_max});
    }
    ll rem1, rem2;
    rem1 = dp[1].first; rem2 = dp[1].second;
    ll tmp1 = a[1]*a[0];
    dp[1].first = dp[1].second = tmp1;
    for(int i = 2; i < n; i++)
    {
        res_min = min(a[i]*rem1, a[i]*rem2);
        res_max = max(a[i]*rem1, a[i]*rem2);
        rem1 = dp[i].first; rem2 = dp[i].second;
        dp[i].first = min(dp[i - 1].first, res_min);
        dp[i].second = max(dp[i - 1].second, res_max);
    }

//    for(int i = 0; i < n; i++) cout << dp[i].first << ' ' << dp[i].second << ' ';
    rem1 = dp[2].first; rem2 = dp[2].second;
    tmp1 = a[1]*a[0]*a[2];
    dp[2].first = dp[2].second = tmp1;
    for(int i = 3; i < n; i++)
    {
        res_min = min(a[i]*rem1, a[i]*rem2);
        res_max = max(a[i]*rem1, a[i]*rem2);
        rem1 = dp[i].first; rem2 = dp[i].second;
        dp[i].first = min(dp[i - 1].first, res_min);
        dp[i].second = max(dp[i - 1].second, res_max);
    }
    for(int i = 0; i < n; i++)
    {
        if(i < 2) cout << 0 << ' ';
        else if(i == 2) cout << a[0]*a[1]*a[2] << ' ';
        else cout << dp[i].second << ' ';
    }
    return 0;
}