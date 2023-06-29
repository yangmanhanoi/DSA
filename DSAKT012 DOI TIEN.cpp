#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k;
int a[35];
ll ans = 1e9;
vector<int> vs;
void Try(int i, ll sum = 0)
{
    if(sum > k) return;
    if(sum == k)
    {
        ans = min(ans, (ll)vs.size());
        return;
    }
    for(int j = i; j <= n; j++)
    {
        vs.push_back(a[j]);
        Try(j + 1, sum + a[j]);
        vs.pop_back();
    }
}
int main()
{
    faster()
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    Try(1);
    if(ans == 1e9) cout << -1;
    else cout << ans;
    ans = 1e9;
    return 0;
}