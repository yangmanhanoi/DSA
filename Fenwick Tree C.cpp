#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll a[60005];
ll Fen[1000005] = {};
ll get(int idx)
{
    if(idx == 0) return 0;
    ll ans = 0;
    while(idx > 0)
    {
        ans += Fen[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
void update(int idx)
{
    while(idx <= 1e6)
    {
        Fen[idx] += 1;
        idx += idx & (-idx);
    }
}
int main()
{
    faster()
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll cnt = 0;
    for(int i = n; i >= 1; i--)
    {
        ll val = get(a[i] - 1);
        update(a[i]);
        cnt += val;
    }
    cout << cnt << endl;
}