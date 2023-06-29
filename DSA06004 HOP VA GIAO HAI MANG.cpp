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
        int a[n + 5], b[m + 5];
        set<int> s, s2;
        unordered_map<int,int> mp;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
            mp[a[i]] = 1;
        }
        for(int i = 1; i <= m; i++)
        {
            cin >> b[i];
            s.insert(b[i]);
            if(mp[b[i]]) s2.insert(b[i]);
        }
        for(auto &i : s) cout << i << ' ';
        cout << endl;
        for(auto &i : s2) cout << i << ' ';
        cout << endl;
    }
    return 0;
}