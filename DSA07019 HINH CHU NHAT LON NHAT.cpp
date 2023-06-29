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
        for(int i = 0; i < n; i++) cin >> a[i];
        int left[n + 5], right[n + 5];
        stack<int> l, r;
        for(int i = 0; i < n; i++)
        {
            while(!l.empty() and a[l.top()] >= a[i]) l.pop();
            if(l.empty()) left[i] = 0;
            else left[i] = l.top() + 1;
            l.push(i);
        }
        // for(int i = 0; i < n; i++) cout << left[i] << ' ';
        // cout << endl;
        right[n - 1] = n - 1;
        r.push(n - 1);
        for(int i = n - 2; i >= 0; i--)
        {
            while(!r.empty() and a[i] <= a[r.top()]) r.pop();
            if(r.empty()) right[i] = n - 1;
            else right[i]= r.top() - 1;
            r.push(i);
        }
      //  for(int i = 0; i < n; i++) cout << right[i] << ' ';
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ll tmp = 1ll * (right[i] - left[i] + 1) * a[i];
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}