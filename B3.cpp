#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int a[1000005] = {};
int lazy[4000005], ST[4000005];
// St luu so lan update cua gia tri neu le thi in ra 1 chan in ra 0
void pushDown(int idx)
{
    ST[idx << 1] += lazy[idx];
    ST[(idx << 1) + 1] += lazy[idx];
    lazy[idx << 1] += lazy[idx];
    lazy[(idx << 1) + 1] += lazy[idx];
    lazy[idx] = 0; 
}
void update(int idx, int l, int r, int lq, int rq)
{
    if(lq > r or rq < l) return;
    if(lq <= l and r <= rq)
    {
        ST[idx]++;
        lazy[idx]++;
        return;
    }
    int mid = (l + r) >> 1;
    pushDown(idx);
    update(idx << 1, l , mid, lq, rq);
    update((idx << 1) + 1, mid + 1, r, lq, rq);
}
void get(int idx, int l, int r)
{
    if(l == r)
    {
        cout << ST[idx] % 2 << ' ';
        return;
    }
    int mid = (l + r) >> 1;
    pushDown(idx);
    get(idx << 1, l, mid);
    get((idx << 1) + 1, mid + 1, r);
}
int main()
{
    faster()
    int n, q; cin >> n >> q;
    while(q--)
    {
        int x, y; cin >> x >> y;
        update(1, 1, n, x, y);
    }
    get(1, 1, n);
}