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
        int n; cin >> n;
        int a[n + 5], f[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        ll left[n + 5], right[n + 5], dp[n + 5];
        left[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            left[i] = a[i];
            for(int j = i - 1; j >= 1; j--)
            {
                if(a[i] > a[j]) left[i] = max(left[i], left[j] + a[i]);
            }
        }
        right[n] = a[n];
        for(int i = n - 1; i >= 1; i--)
        {
            right[i] = a[i];
            for(int j = i + 1; j <= n; j++)
            {
                if(a[i] > a[j]) right[i] = max(right[i], right[j] + a[i]);
            }
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, left[i] + right[i] - a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}