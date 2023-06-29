#include<bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster();
    test()
    {
        ll n , k; cin >> n >> k;
        ll a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        ll cnt = 0;
        for(int i = 0; i < n - 2; i++)
        {
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                if(a[l] + a[r] + a[i] >= k) --r;
                else
                {
                    cnt += (r - l);
                    l++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}