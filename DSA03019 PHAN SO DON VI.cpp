#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define test() \
    ll t;     \
    cin >> t;  \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
void solve(ll p, ll q)
{
    int x = 0;
    while(1)
    {
        if(q % p == 0)
        {
            cout << "1/" << q/p << endl;
            return;
        }
        x = q/p + 1;
        cout << "1/" << x << " + ";
        p = x*p - q;
        q *= x;
    }
}
int main()
{
    faster()
    test()
    {
        ll p, q; cin >> p >> q;
        solve(p,q);
    }
    return 0;
}