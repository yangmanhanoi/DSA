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
        int n, m; cin >> n >> m;
        int check = 0;
        if(n >= m) check = 1;
        else
        {
            if(n >= 4 or(n == 2 and m == 3)) check = 1;
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}