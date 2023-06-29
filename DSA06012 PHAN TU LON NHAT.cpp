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
        int n, k; cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, greater<int>());
        for(int i = 0; i < k; i++) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}