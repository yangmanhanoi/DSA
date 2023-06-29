#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const ll MOD = 1e9 + 7;
int main()
{
    faster()
    test()
    {
        ll n; cin >> n;
        ll ans = 0;
        ll tmp = ((337*n) % MOD) * ((n + 1) % MOD);
        tmp %= MOD;
        tmp *= (2*n + 1) % MOD;
        tmp %= MOD;
        ll tmp2 = ((674*n) % MOD) * ((n - 1) % MOD);
        tmp2 %= MOD;
        tmp2 *= (n + 1) % MOD;
        tmp2 %= MOD;
        cout << (tmp + tmp2) % MOD<< endl;
    }
    return 0;
}