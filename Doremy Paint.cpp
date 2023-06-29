#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
        int f[n + 5] = {};
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
        }
        int l = 1, r = n;
        for(int i = 1; i <= n; i++)
        {
            if(f[a[i]] > 1)
            {
                l = i;
                break;
            }
        }
        for(int i = n; i >= 1; i--)
        {
            if(f[a[i]] > 1)
            {
                r = i;
                break;
            }
        }
        cout << l << ' ' << r << endl;
    }
    return 0;
}