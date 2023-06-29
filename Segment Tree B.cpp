#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int ST[40000005];
int a[1000005];
void buildTree(int idx, int l, int r)
{
    if(l == r)
    {
        ST[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(idx << 1, l, mid);
    buildTree((idx << 1) + 1, mid + 1, r);
    ST[idx] = max(ST[idx << 1], ST[(idx << 1) + 1]);
}
int getMax(int idx, int L , int R, int l_query, int r_query)
{
    if(l_query > R or r_query < L)
    {
        return -1e9 - 7;
    }
    if(l_query <= L and r_query >= R)
    {
        return ST[idx];
    }
    int mid = (L + R)/2;
    int maxLeft = getMax(idx*2, L, mid, l_query, r_query);
    int maxRight = getMax(idx*2 + 1, mid + 1, R, l_query,r_query);
    return max(maxLeft, maxRight);
}
void update(int idx, int x, int y, int L, int R)
{
    if(L == R and L == x)
    {
        a[x] = y;
        ST[idx] = a[x];
        return;
    }
    if(x > R or x < L) return;
    int mid = (L + R) >> 1;
    update(idx << 1, x, y, L, mid);
    update((idx << 1) + 1, x, y, mid + 1, R);
    ST[idx] = max(ST[idx << 1], ST[(idx << 1) + 1]);
}
int main()
{
    faster()
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    buildTree(1, 1, n);
    while(q--)
    {
        int k, x, y;
        cin >> k >> x >> y;
        if(k == 1) update(1, x, y, 1, n);
        else cout << getMax(1, 1, n, x, y) << endl;
    }
    return 0;
}