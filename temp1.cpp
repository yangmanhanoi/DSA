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
        int n; cin >> n;
        int a[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        int cnt0[n + 5] = {}, cnt1[n + 5]= {};
        for(int i = n; i >= 1; i--)
        {
            if(a[i] == 0) cnt0[i] = cnt0[i + 1] + 1;
            else cnt0[i] = cnt0[i + 1];
        }
        for(int i = 1; i <= n; i++)
        {
            if(a[i]) cnt1[i] = cnt1[i - 1] + 1;
            else cnt1[i] = cnt1[i - 1];
        }
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i]) sum += cnt0[i];
        }
        int tmp = sum;
        for(int i = 1; i <= n; i++)
        {
            if(a[i]) sum = max(sum, tmp - cnt0[i] + cnt1[i - 1]);
            else sum = max(sum, tmp - cnt1[i - 1] + cnt0[i + 1]);
        }
        cout << sum << endl;
    }
    return 0;
}