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
        int n, s, m; cin >> n >> s >> m;
        if(n < m or ((6*n) < (7*m) and s > 6))
        {
            cout << -1 << endl;
            continue;
        }
        int days = (m*s)/n;
        if((m*s) % n != 0) days++;
        cout << days <<endl;
    }
    return 0;
}