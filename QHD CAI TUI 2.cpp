// Đã tham khảo Phạm Nam
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    int n, v; cin >> n >> v;
    int w[n + 5], x[n + 5];
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i] >> x[i];
        sum += x[i];
    }
    int dp[n + 5][sum + 5];
    int ans = -1;
    for(int i = 1; i <= sum; i++)
    {
        dp[0][i] = 1e9;
    }
    dp[1][1] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= sum; j++)
        {
            if(j >= x[i])
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - x[i]] + w[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            if(dp[i][j] <= v) ans = max(ans, j);
        }
    }
    cout << ans << endl;
    return 0;
}