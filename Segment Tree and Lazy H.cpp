#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll a[100005];
ll ST[400005], lazy[400005] = {};
void buildtree(int idx, int l, int r)
{
    if(l == r)
    {
        ST[idx] = a[l];
    }
    int mid = (l+ r) >> 1;
    buildtree(idx << 1, l, mid);
    buildtree((idx << 1) + 1, mid + 1, r);
    ST[idx] = ST[idx << 1] + ST[(idx << 1) + 1];
}
void pushDown(int idx, int l, int r, int mid)
{
    ST[idx << 1] += lazy[idx] * (mid - l + 1);
    ST[(idx << 1) + 1] += lazy[idx] * (r - mid);
    lazy[idx << 1] += lazy[idx];
    lazy[(idx << 1)+ 1] += lazy[idx];
    lazy[idx] = 0;
}
void update(int idx, int L , int R, int lq, int rq, int val)
{
    if(L > rq or R < lq) return;
    if(lq <= L and R <= rq)
    {
        ST[idx] += val * (R - L + 1);
        lazy[idx] += val;
        return;
    }
    int mid = (L + R) >> 1;
    pushDown(idx, L, R, mid);
    update(idx << 1, L, mid, lq, rq, val);
    update((idx << 1) + 1, mid + 1, L, lq, rq, val);
}
ll get(int idx, int L, int R, int x)
{
    if(L > x or R < x) return 0;
    if(L == x and R == x)
    {
        return ST[idx];
    }
    int mid = (L + R) >> 1;
    pushDown(idx, L, R, mid);
    get(idx << 1, L, mid, x);
    get((idx << 1) + 1, mid + 1, R, x);
    ST[idx] = ST[idx << 1] + ST[(idx << 1) + 1];
}
int main()
{
    faster()
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    buildtree(1, 1, n);
    while(q--)
    {
        int k, x, y, val; cin >> k;
        if(k == 1)
        {
            cin >> x >> y >> val;
            update(1, 1, n, x, y, val);
        }
        else
        {
            cin >> x;
            cout << get(1, 1, n, x) << endl;
        }
    }
    return 0;
}