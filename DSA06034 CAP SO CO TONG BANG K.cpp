#include<bits/stdc++.h>
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
        int n, k; cin >> n >> k;
        int a[n];
        unordered_map<ll, ll> mp;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        ll cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(mp[a[i]] > 0 and mp[k - a[i]] > 0 and 2*a[i] != k)
            {
                cnt += (ll)mp[a[i]]*mp[k - a[i]];
                mp[a[i]] = mp[k - a[i]] = 0;
            }
            else if(mp[a[i]] > 0 and 2*a[i] == k)
            {
                cnt += (ll)((mp[a[i]])*(mp[a[i]] - 1))/2;
                mp[a[i]] = 0;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}