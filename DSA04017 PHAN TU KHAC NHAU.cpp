#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int binSearch(ll a[], ll b[], int l, int r)
{
    int tmp;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid] != b[mid])
        {
            tmp = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return tmp;
}
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        ll a[n + 5], b[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n - 1; i++) cin >> b[i];
        if(a[1] != b[1]) cout << 1 << endl;
        else if(a[n] != b[n - 1]) cout << n << endl;
        else cout << binSearch(a, b, 1, n - 1) << endl;
    }
    return 0;
}