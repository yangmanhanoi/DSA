#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster();
    test()
    {
        int n, m; cin >> n >> m;
        int a[n],b[m];
        int maxA = -1e9, minB = 1e9; 
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            maxA = max(maxA, a[i]);
        }
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
            minB = min(minB, b[i]);
        }
        ll ans = 1ll * maxA * minB;
        cout << ans << endl;
    }
    return 0;
}