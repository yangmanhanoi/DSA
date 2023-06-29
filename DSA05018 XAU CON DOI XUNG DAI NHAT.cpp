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
        string s; cin >> s;
        int n = s.size();
        s = "*" + s;
        int dp[1005][1005] = {};
        for(int i = 1; i <= n; i++) dp[i][i] = 1;
        int ans = 0;
        for(int len = 2; len <= n; len++)
        {
            for(int i = 1; i <= n - len + 1; i++)
            {
                int j = n + len - 1;
                if(len == 2 and s[i] == s[j]) dp[i][j] = 1;
                else
                {
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                }
                if(dp[i][j]) ans = max(ans, len);
            }
        }
        cout << ans << endl;
    }
    return 0;
}