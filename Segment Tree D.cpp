#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() ll t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll a[1000005];
struct node
{
    ll max1, max2, max3, min1, min2;
};
node ST[4000005];
void updateMax(ll &max1,ll &max2,ll &max3,ll val)
{
    if(val >= max1)
    {
        max3 = max2;
        max2 = max1;
        max1 = val;
    }
    else if(val >= max2)
    {
        max3 = max2;
        max2 = val;
    }
    else if(val >= max3) max3 = val;
}
void updateMin(ll &min1, ll &min2, ll val)
{
    if(val <= min1)
    {
        min2 = min1;
        min1 = val;
    }
    else if(val <= min2) min2 = val;
}
void buildTree(ll idx, ll l, ll r)
{
    if(l == r)
    {
        ST[idx] = (node){a[l], (ll)-1e9, (ll)-1e9, a[l], (ll)1e9};
        cout << idx << ' ' <<  ST[idx].max1 << ' ' << ST[idx].max2 << ' ' << ST[idx].max3 << ' ' << ST[idx].min1 << ' ' << ST[idx].min2 << endl;
        return;
    }
    ll mid = (l + r) >> 1;
    buildTree(idx << 1, l, mid);
    buildTree((idx << 1) + 1, mid + 1, r);
    node res = {(ll)-1e9, (ll)-1e9, (ll)-1e9, (ll)1e9, (ll)1e9};
    updateMax(res.max1, res.max2, res.max3, ST[idx << 1].max1);
    updateMax(res.max1, res.max2, res.max3, ST[idx << 1].max2);
    updateMax(res.max1, res.max2, res.max3, ST[idx << 1].max3);
    updateMax(res.max1, res.max2, res.max3, ST[(idx << 1) + 1].max1);
    updateMax(res.max1, res.max2, res.max3, ST[(idx << 1) + 1].max2);
    updateMax(res.max1, res.max2, res.max3, ST[(idx << 1) + 1].max3);
    updateMin(res.min1, res.min2, ST[idx << 1].min1);
    updateMin(res.min1, res.min2, ST[idx << 1].min2);
    updateMin(res.min1, res.min2, ST[(idx << 1) + 1].min1);
    updateMin(res.min1, res.min2, ST[(idx << 1) + 1].min2);
    ST[idx] = res;
}
void update(ll idx, ll x, ll y, ll l, ll r)
{
    if(x < l or x > r) return;
    if(l == r and r == x)
    {
        ST[idx] = (node){y, (ll)-1e9, (ll)-1e9, y, (ll)1e9};
        return;
    }
    ll mid = (l + r) >> 1;
    update(idx << 1,x, y, l, mid);
    update((idx << 1) + 1,x ,y, mid + 1, r);
    node res = {(ll)-1e9, (ll)-1e9, (ll)-1e9, (ll)1e9, (ll)1e9};
    updateMax(res.max1, res.max2, res.max3, ST[idx << 1].max1);
    updateMax(res.max1, res.max2, res.max3, ST[idx << 1].max2);
    updateMax(res.max1, res.max2, res.max3, ST[idx << 1].max3);
    updateMax(res.max1, res.max2, res.max3, ST[(idx << 1) + 1].max1);
    updateMax(res.max1, res.max2, res.max3, ST[(idx << 1) + 1].max2);
    updateMax(res.max1, res.max2, res.max3, ST[(idx << 1) + 1].max3);
    updateMin(res.min1, res.min2, ST[idx << 1].min1);
    updateMin(res.min1, res.min2, ST[idx << 1].min2);
    updateMin(res.min1, res.min2, ST[(idx << 1) + 1].min1);
    updateMin(res.min1, res.min2, ST[(idx << 1) + 1].min2);
    ST[idx] = res;
}
node getNode(ll idx, ll L, ll R, ll lq, ll rq)
{
    if(R < lq or L > rq) return (node){(ll)-1e9,(ll)-1e9,(ll)-1e9,(ll)1e9,(ll)1e9};
    if(lq <= L and R <= rq)
    {
        return ST[idx];
    }
    ll mid = (L + R) >> 1;
    node left = getNode(idx << 1, L, mid,lq, rq);
    node right = getNode((idx << 1) + 1, mid + 1, R, lq, rq);
    node res = {(ll)-1e9, (ll)-1e9, (ll)-1e9, (ll)1e9, (ll)1e9};
    updateMax(res.max1, res.max2, res.max3, left.max1);
    updateMax(res.max1, res.max2, res.max3, left.max2);
    updateMax(res.max1, res.max2, res.max3, left.max3);
    updateMax(res.max1, res.max2, res.max3, right.max1);
    updateMax(res.max1, res.max2, res.max3, right.max2);
    updateMax(res.max1, res.max2, res.max3, right.max3);
    updateMin(res.min1, res.min2, left.min1);
    updateMin(res.min1, res.min2, left.min2);
    updateMin(res.min1, res.min2, right.min1);
    updateMin(res.min1, res.min2, right.min2);
    return res;
}
int main()
{
    faster()
    ll n, q; cin >> n >> q;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    buildTree(1, 1, n);
    for(int i = 1; i <= 7; i++)
    {
        cout << i << ' ' <<  ST[i].max1 << ' ' << ST[i].max2 << ' ' << ST[i].max3 << ' ' << ST[i].min1 << ' ' << ST[i].min2 << endl;
    } 
    // while(q--)
    // {
    //     ll k, x, y; cin >> k >> x >> y;
    //     if(k == 1)
    //     {
    //         update(1, x, y, 1, n);
    //     }
    //     else
    //     {
    //         node tmp = getNode(1, 1, n, x, y);
    //         ll ans = max(tmp.max1*tmp.max2*tmp.max3, tmp.max1*tmp.min1*tmp.min2);
    //         cout << ans << endl;
    //     }
    return 0;
}