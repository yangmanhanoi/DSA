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
        int n, k; cin >> n >> k;
        int a[n + 5];
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] %= k;
        }
        // Độ dài xâu con lớn nhất tính đến i mà chia dư cho k đc j
        // Kết quả bài toán là dp[n][0]
        int dp[n + 5][55];
        dp[0][0] = 0;
        for(int i = 1; i < k; i++) dp[0][i] = -1e9;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= k - 1; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - a[i] + k) % k] + 1);
            }
        }
        cout << dp[n][0] << endl;
    }
    return 0;
}