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
    int idx = 1;
    test()
    {
        int n; cin >> n;
        int a[n + 5][n + 5];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int dp[77000] = {};
        for(int mask = 0; mask <= (1 << n) - 1; mask++)
        {
            int dem = 0;
            for(int i = 0; i < n; i++)
            {
                if((mask & (1 << i)) == 0) dem++;
            }
            for(int j = 0; j < n; j++)
            {
                if((mask & (1 << j)) == 0)
                {
                    dp[mask | (1 << j)] = max(dp[mask | (1 << j)], dp[mask] + a[n - dem][j]);
                }
            }
        }
        cout << "Case " << idx << ": " << dp[(1 << n) - 1] << endl;
        idx++;
    }
    return 0;
}