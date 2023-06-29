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
        int n, v; cin >> n >> v;
        int w[n + 5], x[n + 5], dp[v + 5] = {};
        for(int i = 1; i <= n; i++) cin >> w[i];
        for(int i = 1; i <= n; i++) cin >> x[i];
        for(int i = 1; i <= n; i++)
        {
            for(int j = v; j >= w[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + x[i]);
            }
        }
        cout << dp[v] << endl;
    }
    return 0;
}