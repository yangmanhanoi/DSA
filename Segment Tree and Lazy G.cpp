#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() ll t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll a[100005];
ll ST[400005] = {};
ll lazy[400005];
ll n, q;
void buildTree(ll idx, ll l, ll r)
{
    if(l == r)
    {
        ST[idx] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    buildTree(idx << 1, l , mid);
    buildTree((idx << 1) + 1, mid + 1, r);
    ST[idx] = ST[idx << 1] + ST[(idx << 1) + 1];
}
void pushDown(ll idx, ll l, ll r, ll mid)
{
    ST[idx << 1] += lazy[idx] * (mid - l + 1);
    ST[(idx << 1) + 1] += lazy[idx] * (r - mid);
    lazy[idx << 1] += lazy[idx];
    lazy[(idx << 1) + 1] += lazy[idx];
    lazy[idx] = 0;
}
void update(ll idx, ll L, ll R, ll lq, ll rq, ll val)
{
    if(L > rq or R < lq) return;
    if(lq <= L and R <= rq)
    {
        lazy[idx] += val;
        ST[idx] += (R - L + 1) * val;
        return;
    }
    ll mid = (L+ R) >> 1;
    pushDown(idx,L, R, mid);
    update(idx << 1, L, mid, lq, rq, val);
    update((idx << 1) + 1, mid + 1, R, lq, rq, val);
    ST[idx] = ST[idx << 1] + ST[(idx << 1) + 1];
}
ll getSum(ll idx, ll L, ll R, ll lq, ll rq)
{
    if(L > rq or R < lq) return 0;
    if(lq <= L and R <= rq) return ST[idx];
    ll mid = (L + R) >> 1;
    pushDown(idx, L, R, mid);
    ll left = getSum(idx << 1, L, mid, lq, rq);
    ll right = getSum((idx << 1) + 1, mid + 1, R, lq, rq);
    return left + right;
}
int main()
{
    faster()
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    buildTree(1, 1, n);
    while(q--)
    {
        ll k,x, y, val; cin >> k;
        if(k == 1)
        {
            cin >> x >> y >> val;
            update(1, 1, n, x, y, val);
            //  for(ll i = 1; i <= 20; i++) cout << lazy[i] << ' ';
            //  cout << endl;
        }
        else
        {
            cin >> x >> y;
            cout << getSum(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}