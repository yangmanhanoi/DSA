#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster();
    ll dp[55];
    // dp[i]: số cách để đến được bậc thang thứ i
    // tại bậc 0 thì chỉ có 1 cách là không bước.
    // bậc 1 thì chỉ có 1 cách là 1 bước
    // dp[2] thì có 2 cách bước đến bậc 1 + 1 bước và từ bậc 0 -> 2
    // Số cách bước lên bậc i chính là tổng số cách đến đc các bậc i - 1, i - 2, i - 3
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= 52; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    test()
    {
        int n; cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}