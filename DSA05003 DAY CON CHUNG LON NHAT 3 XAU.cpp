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
        int n, m, k; cin >> n >> m >> k;
        string s1, s2,s3; cin >> s1 >> s2 >> s3;
        int dp[n + 5][m + 5][k + 5];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                for(int x = 1; x <= k; x++)
                {
                    if(s1[i - 1] == s2[j - 1] and s1[i - 1] == s3[x - 1]) dp[i][j][x] = dp[i - 1][j - 1][x - 1] + 1;
                    else    dp[i][j][x] = max({dp[i - 1][j][x], dp[i][j - 1][x], dp[i][j][x - 1]});
                }
            }
        }
        cout << dp[n][m][k] << endl;
    }
    return 0;
}