#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
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
        sort(a + 1, a + n + 1);
        int mid = (1 + n) / 2;
        int l = 1, r = mid;
        ll cnt = 0;
        while(l <= mid and r <= n)
        {
            if(a[l]*2 <= a[r])
            {
                l++; r++; cnt++;
            }
            else r++;
        }
        cout << n - cnt << endl;
    }
    return 0;
}