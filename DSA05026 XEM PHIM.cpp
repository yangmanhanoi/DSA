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
    int C, n; cin >> C >> n;
    int a[n + 5], dp[C + 5] = {};
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = C; j >= a[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
//    for(int i = 1; i <= n; i++) cout << dp[i] << ' ';
   cout << dp[C] << endl;
    return 0;
}