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
        int par, child;
        char c;
        set<int> s;
        while(n--)
        {
            cin >> par >> child >> c;
            s.insert(par);
            s.insert(child);
        }
        for(auto &i : s) cout << i << ' ';
        cout << endl;
    }
    return 0;
}