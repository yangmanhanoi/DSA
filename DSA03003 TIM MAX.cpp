#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int MOD = 1E9 + 7;
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int a[n + 5];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += (i * a[i]) % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}