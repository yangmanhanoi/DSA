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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int pos = upper_bound(a.begin(), a.end(), k) - a.begin();
        if(pos == n or pos == 0) cout << -1 << endl;
        else
        {
            cout << pos << endl;
        }
    }
    return 0;
}