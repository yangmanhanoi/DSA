#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
        int a[n + 5], b[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1, greater<int>());
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans += 1ll*a[i]*b[i];
        }
        cout << ans << endl;
    }
    return 0;
}