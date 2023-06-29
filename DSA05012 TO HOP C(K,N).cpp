#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int MOD = 1E9 + 7;
ll binPow(int n, int k)
{
    if(k == 1) return n;
    ll tmp = binPow(n, k/2);
    tmp *= tmp;
    if(k % 2 == 1) return (1ll *n * (tmp % MOD)) % MOD;
    else return tmp % MOD;
}
ll calc(int n, int k)
{
    ll f[1005], tmp[1005];
    if(k == 1) return n;
    tmp[1] = n;
    for(int i = 2; i <= k; i++)
    {
        tmp[i] = binPow(i, MOD - 2) * (tmp[i - 1] % MOD);
        tmp[i] %= MOD;
        tmp[i] *= (n - i + 1)% MOD;
        tmp[i] %= MOD;
    }
    return tmp[k];
}
int main()
{
    faster()
    test()
    {
        int n, k; cin >> n >> k;
        cout << calc(n, k) << endl;
    }
    return 0;
}