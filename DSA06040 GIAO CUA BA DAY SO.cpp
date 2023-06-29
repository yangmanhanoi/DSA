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
        int n, m, k;
        cin >> n >> m >> k;
        ll a[n], b[m], c[k];
        unordered_map<ll,ll> mp;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]] = 1;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
            if(mp[b[i]])
            {
                mp[b[i]] = 2;
            }
        }
        multiset<ll> s;
        for(int i = 0; i < k; i++)
        {
            cin >> c[i];
            if(mp[c[i]] == 2)
            {
                s.insert(c[i]);
            }
        }
        if(s.size() == 0) cout << -1;
        else
        {
            for(auto &i : s) cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}