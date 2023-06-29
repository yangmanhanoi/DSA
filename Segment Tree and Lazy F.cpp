#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() ll t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll a[100005] = {};
ll ST[400005] = {}, lazy[400005];
void pushDown(ll idx)
{
    ST[idx << 1] += lazy[idx];
    ST[(idx << 1) + 1] += lazy[idx];
    lazy[idx << 1] += lazy[idx];
    lazy[(idx << 1) + 1] += lazy[idx];
    lazy[idx] = 0;
}
void update(ll idx, ll L, ll R, ll lq, ll rq, ll val)
{
    if(L > rq or R < lq) return;
    if(L >= lq and R <= rq)
    {
        ST[idx] += val;
        lazy[idx] += val;
        return;
    }
    pushDown(idx);
    ll mid = (L + R) >> 1;
    update(idx << 1, L, mid, lq, rq, val);
    update((idx << 1) + 1, mid + 1, R, lq, rq, val);
    ST[idx] = max(ST[idx << 1], ST[(idx << 1) + 1]);
}
ll getMax(ll idx, ll L, ll R, ll lq, ll rq)
{
    if(rq < L or lq > R) return -1e9;
    if(lq <= L and R <= rq)
    {
        return ST[idx];
    }
    ll mid = (L + R) >> 1;
    pushDown(idx);
    ll left = getMax(idx << 1, L, mid, lq, rq);
    ll right = getMax((idx << 1) + 1, mid + 1, R, lq, rq);
    return max(left, right);
}
int main()
{
    faster()
    ll n, q; cin >> n >> q;
    while(q--)
    {
        ll k, x, y, z; cin >> k;
        if(k == 1)
        {
            cin >> x >> y >> z;
            update(1, 1, n, x, y, z);
        }
        else
        {
            cin >> x >> y;
            cout << getMax(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}