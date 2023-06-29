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
        string s; cin >> s;
        int f[30] = {};
        int x = -1;
        for(auto i : s) f[i - 'A']++;
        for(auto i : f) x = max(x, i);
        int k = (n - 1)*(x - 1);
        if(s.size() - x >= k) cout << 1 << endl;
        else cout << -1 << endl;
    }
    return 0;
}