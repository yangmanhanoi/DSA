#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const ll MOD = 1e9 + 7;
ll dp[1005][1005];
ll binMul(ll a, ll totalChildren)
{
    if(totalChildren == 1) return a;
    if(totalChildren == 0) return 1LL;
    ll tmp = binMul(a, totalChildren / 2);
    (tmp = (tmp * tmp) % MOD) %= MOD;
    if (totalChildren & 1)
        (tmp = (tmp * a) % MOD) %= MOD;
    return tmp;
}
int main()
{
    faster()
    test()
    {
        ll n, k; cin >> n >> k;
        ll x;
        ll totalChildren = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> x;
            totalChildren += x;
        }
        // Tìm số sắp xếp các bà mẹ
        // dp[i][j] : là số cách sắp xếp i bà mẹ vào j bàn
        // Kết quả của bài toán sắp xếp là: dp[n][i: 1 -> k]
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(ll i = 0; i <= n; i++)
        {
            for(ll j = 0; j <= k; j++)
            {
                (dp[i + 1][j + 1] += (k - j) * dp[i][j] % MOD) %= MOD;
                (dp[i + 1][j] += j * dp[i][j] % MOD) %= MOD;
            }
        }
        // Nếu các bà mẹ ngồi j bàn thì mỗi đứa con sẽ có k - j + 1 cách chọn chỗ ngồi
        // Do nó có thể ngồi vào các bàn trống còn lại và ngồi vào bàn với mẹ nó -> k - j + 1
        // Có totalChildren đứa thì sẽ có (k - j + 1)^totalChildren
        ll ans = 0;
        for(ll i = 1; i <= k; i++)
        {
            (ans += (dp[n][i] * binMul(k - i + 1, totalChildren) % MOD)) %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}