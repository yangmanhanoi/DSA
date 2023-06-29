#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() ll t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll Fen[1000005] = {};
ll a[1000005];
ll n, q;
void buildTree(ll idx, ll val)
{
    while (idx <= n)
    {
        Fen[idx] += val;
        idx += (idx & (-idx));
    }
}
void update(ll idx, ll val)
{
    while(idx <= n)
    {
        Fen[idx] += val;
        idx += (idx & (-idx));
    }
}
ll get(ll idx)
{
    ll ans = 0;
    while(idx > 0)
    {
        ans += Fen[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
int main()
{
    faster()
    cin >> n >> q;
    for(ll i = 1; i <=n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++)
    {
        buildTree(i, a[i]);
    }
    while(q--)
    {
        ll k, x, y;
        cin >> k;
        if(k == 1)
        {
            cin >> x >> y;
            update(x, y);
        }
        else
        {
            cin >> x >> y;
            cout << get(y) - get(x - 1) << endl;
        }
    }
    return 0;
}