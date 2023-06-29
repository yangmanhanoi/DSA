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
        int dp[n + 5][n+ 5] = {};
        int ans = 1;
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            if(i != n - 1 and s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
        for(int j = 3; j < n; j++)
        {
            for(int i = 0; i < j; i++)
            {
                if(s[i] == s[j] and dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    ans = max(ans, j - i + 1);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}