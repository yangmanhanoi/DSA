#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int MOD = 1e9+7;
int main()
{
    faster()
    ll dp[105][10], value[105] = {};
    value[0] = 0; value[1] = 10;
    for(int i = 0; i <= 9; i++)
    {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= 100; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            if(j == 0)
            {
                dp[i][j] = value[i - 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
            }
            value[i] += dp[i][j];
        }
        value[i] %= MOD;
        if(value[i] < 0) value[i] = MOD + value[i];
    }
    test()
    {
        int n; cin >> n;
        cout << value[n] << endl;
    }
    return 0;
}