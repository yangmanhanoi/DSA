#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define vi vector<ll>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i <= b; ++i)
#define FORD(i, a, b) for(ll i = a; i >= b; --i)
#define F(i, a, b) for(ll i = a; i < b; ++i)
#define FD(i, a, b) for(ll i = a; i > b; --i)
#define test() ll t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
vector<ll> preSum(100005, 0);
int binSearch(int l, int r, int k)
{
    int mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(preSum[r] - preSum[mid - 1] <= k)
        {
            k -= preSum[r] - preSum[mid - 1];
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return mid + 1;
} 
int main()
{
    faster()
    test()
    {
        ll n, s, k;
        cin >> n >> s >> k;
        ll a[n + 5];
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            preSum[i] = a[i] + preSum[i - 1];
        }
        if(preSum[s] <= k) cout << 1 << endl;
        else{
            cout << binSearch(1, s, k) << endl;
        }
    }
    return 0;
}