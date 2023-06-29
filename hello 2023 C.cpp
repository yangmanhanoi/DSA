#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        ll n, m; cin >> n >> m;
        ll a[n + 5];
        FOR(i, 0, n - 1) cin >> a[i];
        priority_queue<ll> q;
        ll ans = 0, sum = 0;
        priority_queue<ll, vector<ll>, greater<>> pq;
        FOR(i, m, n - 1)
        {
            if(a[i] < 0) pq.push(a[i]);
            sum += a[i];
            while(sum < 0)
            {
                ll tmp = pq.top();
                pq.pop();
                sum -= tmp << 1;
                ans++;
            }
        }
        if(a[m - 1] <= 0) sum = a[m - 1];
        else if(m != 1)
        {
            sum = -a[m - 1];
            ans++;
        }
        FORD(i, m - 2, 1)
        {
            if(a[i] > 0) q.push(a[i]);
            sum += a[i];
            while(sum > 0)
            {
                ll tmp = q.top();
                q.pop();
                sum -= tmp << 1;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}