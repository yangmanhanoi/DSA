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
        int k; cin >> k;
        // dp[i][r][rSum][rMul][state]: là số lượng số có i chữ số sao cho số đó chia cho k dư r, tổng các chữ số của nó chia
        // cho k dư rSum, tích các chữ số chia k dư rMul, state = 0,1,2.
        
        if(k >= 82) cout << 0 << endl;
        else
        {
            int dp[15][85][85][85][3] = {};
            for(int i = 1; i <= 9; i++)
            {
                int x = s[0] - '0';
                if(i < x)
                {
                    dp[1][i % k][i % k][i % k][0]++;
                }
                else if(i == x)
                {
                    dp[1][i % k][i % k][i % k][1]++;
                }
                else
                {
                    dp[1][i % k][i % k][i % k][2]++;
                }
            }
            int newR, newRsum, newRMul, newState;
            for(int i = 1; i < s.size(); i++)
            {
                for(int r = 0; r < k; r++)
                {
                    for(int rSum = 0; rSum < k; rSum++)
                    {
                        for(int rMul = 0; rMul < k; rMul++)
                        {
                            for(int state = 0; state < 3; state++)
                            {
                                if(dp[i][r][rSum][rMul][state] == 0) continue;
                                int x = s[i] - '0';
                                for(int j = 0; j <= 9; j++)
                                {
                                    if(state == 1)
                                    {
                                        if(j < x) newState = 0;
                                        else if(j == x) newState = 1;   
                                        else newState = 2;
                                    }
                                    else newState = state;
                                    newR = (r*10 + j) % k;
                                    newRsum = (rSum + j) % k;
                                    newRMul = (rMul * j) % k;
                                    dp[i + 1][newR][newRsum][newRMul][newState] += dp[i][r][rSum][rMul][state];
                                }
                            }
                        }
                    }
                }
            }
            ll ans = 0;
            for(int i = 1; i < s.size(); i++)
            {
                for(int state = 0;state < 3; state ++) ans += dp[i][0][0][0][state];
            }
            for(int state = 0; state < 2; state++) ans += dp[s.size()][0][0][0][state];
            cout << ans << endl;
        }
    }
    return 0;
}