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
        string s; cin >> s;
        int n = s.size();
        string tmp = s;
        reverse(tmp.begin(),tmp.end());
        s = "*" + s;
        tmp = "*" + tmp;
        int dp[1005][1005];
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = 0;
            for(int j = 1; j <= n; j++)
            {
                dp[0][j] = 0;
                if(s[i] == tmp[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
 //       cout << n << ' ' << dp[n][n];
 //       cout << n - dp[n][n] << endl;
 //       cout << dp[n][n] << endl;
        }
    return 0;
}