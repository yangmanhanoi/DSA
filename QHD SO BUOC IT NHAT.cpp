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
        ll dp[105][105] = {};
        for(int i = 0; i <= s1.size(); i++) dp[i][0] = i;
        for(int i = 0; i <= s2.size(); i++) dp[0][i] = i;
        int x = s1.size(), y = s2.size();
        for(int i = 1; i <= x; i++)
        {
            for(int j = 1; j <= y; j++)
            {
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1), dp[i][j - 1] + 1);
                }
            }
        }
        cout << dp[x][y] << endl;
    }
    return 0;
}