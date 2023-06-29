#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define F(i, a, b) for (int i = a; i < b; ++i)
#define FD(i, a, b) for (int i = a; i > b; --i)
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        // int n;
        // cin >> n;
        // int a[n + 5];
        // int dp[n + 5] = {};
        // ll preSum[n + 5] = {};
        // for (int i = 1; i <= n; i++)
        // {
        //     cin >> a[i];
        //     dp[i] = 0;
        //     preSum[i] = preSum[i - 1] + a[i];
        // }
        // ll max_avg = a[0];
        // int st = 0, ans = 1;
        // for (int i = 1; i <= n; i++)
        // {
        //     for(int j = i; j >= 1; j--)
        //     {
        //         if(max_avg < (preSum[i] - preSum[j] + a[i])/(i - j + 1))
        //         {
        //             max_avg = (preSum[i] - preSum[j] + a[i])/(i - j + 1);
        //             ans = max(ans, i - j + 1);
        //         }
        //     }
        // }
        // cout << ans << endl;
        int n, k; cin >> n;
        int a[n + 5];
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<int> dp(n + 5, 0);
        cin >> k;
        int preSum[n + 5] = {};
        preSum[0] = a[0];
        for(int i = 1; i < n; i++)
        {
            preSum[i] = preSum[i - 1] + a[i];
        }
        vector<int> C(n + 1, -1);
        for(int i = 0; i < n; i++)
        {
            if(C[preSum[i] % k] == -1) C[preSum[i] % k] = i;
        }
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(C[preSum[i] % k] != -1)
            {
                ans = max(ans, i - C[preSum[i] % k] + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}