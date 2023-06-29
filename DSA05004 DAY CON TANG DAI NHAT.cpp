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
    int n; cin >> n; 
    // dp[i]: Độ dài xâu con dài nhất tính đến vị trí i
    int a[n + 5], dp[n + 5];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }
    int ans = -1e9;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}