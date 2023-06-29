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
    // faster()
    // test()
    // {
    //     int n; cin >> n;
    //     int a[n];
    //     for(int i = 0; i < n; i++)
    //     {
    //         cin >> a[i];
    //     }
    //     sort(a, a + n);
    //     int y = a[0];
    //     for(int i = 1; i < n; i++)
    //     {
    //         y = __gcd(y, a[i]);
    //     }
    //     cout << a[n - 1] / y << endl;
    // }
    // return 0;
    faster()
    test()
    {
        int n; cin >> n;
        int a[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << endl;
    }
}