#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int MOD = 123456789;
ll binMul(int n, ll k)
{
    if(k == 1) return n;
    ll tmp = binMul(n, k / 2);
    tmp %= MOD;
    tmp *= tmp;
    if(k % 2 == 0) return tmp % MOD;
    else return (n *(tmp % MOD)) % MOD;
}
int main()
{
    faster()
    test()
    {
        ll n; cin >> n;
        cout << binMul(2, n - 1) << endl;
    }
    return 0;
}