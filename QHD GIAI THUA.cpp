#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int MOD = 1000033;
ll binMul(ll a, ll m)
{
    if(m == 1) return a;
    ll tmp;
    tmp = binMul(a, m / 2);
    if(m % 2 == 0) return ((tmp % MOD)*(tmp % MOD))%MOD;
    else return (a%MOD * ((tmp % MOD)*(tmp % MOD))%MOD)%MOD;
}
int main()
{
    faster()
    ll f[1000050];
    f[1] = 1;
    //Mang luu gia tri % MOD cac giai thua
    for(ll i = 2; i < MOD; i++)
    {
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
    test()
    {
        ll l, r, k; cin >> l >> r >> k;
        if(r >= MOD) cout << 0;
        else
        {
            ll res1 =1 , res2 = 1;
            for(int i = 1; i <= r; i++)
            {
                res1 *= f[i];
                res1 %= MOD;
                if(i <= l - 1)
                {
                    res2 *= f[i];
                    res2 %= MOD;
                }
            }
            ll tmp = res1 * binMul(res2, MOD - 2);
            tmp %= MOD;
            ll ans = binMul(tmp, k);
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}