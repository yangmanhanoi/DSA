#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int MOD = 1e9 +7;
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int a[n + 5];
        priority_queue<ll, vector<ll>, greater<>> q;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            q.push(a[i]);
        }
        ll ans = 0;
        while(q.size() != 1)
        {
            ll top1, top2;
            top1 = top2 = 0;
            if(!q.empty())
            {
                top1 = q.top();
                q.pop();
            }
            if(!q.empty())
            {
                top2 = q.top();
                q.pop();
            }
            ans += (top1 + top2) % MOD;
            ans %= MOD;
            q.push((top1 + top2) % MOD);
        }
        cout << ans << endl;
    }
    return 0;
}