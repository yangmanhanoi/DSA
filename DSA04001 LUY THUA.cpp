#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const ll MOD = 1e9 + 7;
ll binMul(ll n, ll k)
{
    if(k == 0) return 1;
    if(k == 1) return n;
    ll tmp = binMul(n, k/2);
    tmp %= MOD;
    tmp *= tmp;
    if(k % 2== 0) return tmp%MOD;
    else return (1LL *n*(tmp % MOD)) % MOD;
}
int main()
{
    faster()
    test()
    {
        ll n; cin >> n;
        string s = to_string(n);
        reverse(s.begin(), s.end());
        ll k = stoll(s);
        cout << binMul(n, k) << endl;
    }
    return 0;
}