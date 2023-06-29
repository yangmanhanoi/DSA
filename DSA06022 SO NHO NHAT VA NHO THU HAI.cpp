#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
        int n; cin >> n;
        int a[n];
        int min1 = 1e9, min2 = 1e9;
        // min1 : So nho nhat
        // min2: so nho thu hai
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++)
        {
            if(a[i] < min1)
            {
                min2 = min1;
                min1 = a[i];
            }
            else if(a[i] > min1 and a[i] < min2)
            {
                min2 = a[i];
            }
        }
        if(min2 == 1e9) cout << -1;
        else cout << min1 << ' ' << min2;
        cout << endl;
    }
    return 0;
}