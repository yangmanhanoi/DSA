#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll a[1000005];
ll ST[4000005];
void buildTree(int idx, int l, int r)
{
    if(l == r)
    {
        ST[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(idx << 1, l , mid);
    buildTree((idx << 1) + 1, mid + 1, r);
    ST[idx] = ST[idx << 1] + ST[(idx << 1) + 1];
}
void update(int idx, int x, int y, int l, int r)
{
    if(l == x and r == x)
    {
        ST[idx] += y;
        return;
    }
    if(x > r or x < l) return;
    int mid = (l + r) >> 1;
    update(idx << 1, x, y, l, mid);
    update((idx << 1) + 1, x, y, mid + 1, r);
    ST[idx] = ST[idx << 1] + ST[(idx << 1) + 1];
}
ll getResult(int idx, int L, int R, int l_query, int r_query)
{
    if(l_query > R or r_query < L) return 0;
    if(l_query <= L and R <= r_query) return ST[idx];
    int mid = (L + R) >> 1;
    ll resLeft = getResult(idx << 1,L, mid, l_query, r_query);
    ll resRight = getResult((idx << 1) + 1, mid + 1, R, l_query, r_query);
    return resLeft + resRight;
}
int main()
{
    faster();
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    buildTree(1, 1, n);
    while (q--)
    {
        int k, x, y; cin >> k >> x >> y;
        if(k == 1) update(1, x, y, 1, n);
        else cout << getResult(1, 1, n, x, y) << endl;
    }
    return 0;
}