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
        int dp[n + 5] = {};
        if(s[0] == '0') cout << 0 << endl;
        else
        {
            int cnt = 0;
            dp[0] = 1;dp[1] = 1;
            for(int i = 2; i <= n; i++)
            {
                string tmp = s.substr(i - 2,2);
                int res = stoi(tmp);
                if((res > 20 and res % 10 == 0) or res == 0)
                {
                    dp[n] = 0;
                    break;
                }
                if(res > 10 and res <= 26 and res % 10 != 0)
                {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
                else
                {
                    if(res != 10 and res != 20) dp[i] = dp[i - 1];
                    else dp[i] = dp[i - 2];
                }
//                cout << dp[i] << ' ' << cnt << endl;
            }
           cout << dp[n] << endl;
        }
    }
    return 0;
}