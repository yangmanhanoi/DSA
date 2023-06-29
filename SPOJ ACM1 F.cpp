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
    ll n; ll k; cin >> n >> k;
    string s = to_string(n);
    int cnt = 0;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] != '0') break;
        else cnt++;
    }
    if(k <= cnt) cout << n << endl;
    else
    {
        // BCNN;
        ll a = 1;
        for(int i = 0; i < k; i++) a*= 10;
        ll ans = (a * n * 1LL) / __gcd(a, n);
        cout << ans << endl;
    }
    
    return 0;
}