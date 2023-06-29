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
        int n, k; cin >> n >> k;
        int a[n + 5], dp[k + 5] = {};
        for(int i = 1; i <= n; i++) cin >> a[i];
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = k; j >= 0; j--)
            {
                if(j < a[i]) continue;
                else
                {
                    if(dp[j - a[i]]) dp[j] = 1;
                }
            }
        }
        if(dp[k]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}