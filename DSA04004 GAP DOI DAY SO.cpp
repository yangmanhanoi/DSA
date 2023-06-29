#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll binSearch(ll n, ll k)
{
    ll x = pow(2, n - 1);
    if(k == x) return n;
    else if(k < x) return binSearch(n - 1, k);
    else return binSearch(n,k - x);
}
int main()
{
    faster()
    test()
    {
        ll n, k; cin >> n >> k;
        cout << binSearch(n, k) << endl;
    }
    return 0;
}