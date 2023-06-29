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
        int n, s; cin >> n >> s;
        int a[n + 5], dp[400005] = {};
        for(int i = 1; i <= n; i++) cin >> a[i];
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = s; j >= a[i]; j--)
            {
                if(dp[j - a[i]]) dp[j] = 1;
            }
        }
        if(dp[s]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}