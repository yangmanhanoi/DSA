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
    ST[idx] = min(ST[idx << 1], ST[(idx << 1) + 1]);
}
int getMin(int idx,int L,int R, int l, int r)
{
    if(r < L or l > R)
    {
        return 1e9 + 7;
    }
    if(L >= l and R <= r) return ST[idx];
    int mid = (L + R) >> 1;
    int minLeft = getMin(idx << 1, L, mid , l , r);
    int minRight = getMin((idx << 1) + 1, mid + 1, R, l, r);
    return min(minLeft, minRight);
}
int main()
{
    faster()
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    buildTree(1, 1, n);
    while(q--)
    {
        int x, y; cin >> x >> y;
        cout << getMin(1, 1, n, x, y) << endl;
    }
    return 0;
}