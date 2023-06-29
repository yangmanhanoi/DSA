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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(),a.end());
        ll ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int pos = lower_bound(a.begin() + i + 1, a.end(), k + a[i]) - a.begin();
            ans += pos - i - 1;
        }
        cout << ans << endl;
    }
    return 0;
}