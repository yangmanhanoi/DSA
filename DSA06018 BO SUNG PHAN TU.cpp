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
        int n; cin >> n;
        int a[n];
        set<int> s;
        int l = 0, r = 1e9;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
            l = max(l, a[i]);
            r = min(r, a[i]);
        }
        cout << l - r + 1 - s.size() << endl;
    }
    return 0;
}