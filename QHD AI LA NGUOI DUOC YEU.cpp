#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    int n, k; cin >> n >> k;
    int dp[k + 5] = {};
    int a[n + 5];
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[0] = 0;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= a[j] and dp[i - a[j]] == 0)
            {
                dp[i] = 1;
                break;
            }
        }
    }
    if(dp[k]) cout << "Kent\n";
    else cout << "Bent\n";
}