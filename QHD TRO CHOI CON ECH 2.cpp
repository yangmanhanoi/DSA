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
        int a[n + 5];
        int dp[n + 5];
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[i] = 1e9;
        }
        dp[1] = 0;
        for(int i = 2; i <= n; i++)
        {
            for(int j = i - k; j < i; j++)
            {
                if(j <= 0) continue;
                else
                {
                    dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
                }
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}