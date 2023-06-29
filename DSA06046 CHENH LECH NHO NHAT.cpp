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
        int a[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        int ans = 1e9;
        for(int i = 2; i <= n; i++)
        {
            ans = min(ans, a[i] - a[i - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}