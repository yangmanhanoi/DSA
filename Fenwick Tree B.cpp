#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() ll t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll n;
ll a[1000005];
ll Fen[1000005] = {};
// Mang dp[x]: độ dài dãy con tăng dài nhất kết thúc tại phần tử có giá trị = x
// Độ dài dãy con tăng dài nhất kết thúc tại x bằng độ dài dãy con tăng dài nhất kết thúc tại 1, 2, .. x - 1 cộng thêm 1 (thêm x vào dãy đó)
//. => dp[x] = dp[1 -> x- 1] + 1;
//Ta có cây Fen quản lý mảng dp: Fen[i] = max(dp[1], dp[2], ... dp[i - 1])

// Tìm độ dài dãy con tăng dài nhất kết thúc tại 1,2,.. idx
ll get(ll idx)
{
    if(idx == 0) return 0;
    ll tmp = -1e9;
    while (idx > 0)
    {
        tmp = max(tmp, Fen[idx]);
        idx -= (idx & (-idx));
    }
    return tmp;
}

// Cập nhật giá trị lên các nút cha
void update(ll idx, ll val)
{
    while (idx <= 1e6)
    {
        Fen[idx] = max(Fen[idx], val);
        idx += (idx & (-idx));
    }
}
int main()
{
    faster()
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll ans = -1e9;
    for(ll i = 1; i <= n; i++)
    {
        ll len = get(a[i] - 1) + 1; // Tìm độ dài dãy con tăng dài nhất kết thúc tại a[i]
        update(a[i], len);
        ans = max(ans, len);
    }
    cout << ans << endl;
    return 0;
}