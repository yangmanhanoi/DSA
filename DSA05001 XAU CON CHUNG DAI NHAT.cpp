#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t;cin.ignore(); while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        string s1, s2; cin >> s1 >> s2;
        int dp[1005][1005];
        int n = s1.size(), m = s2.size();
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = 0;
            for(int j = 1; j <= m; j++)
            {
                dp[0][j] = 0;
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}