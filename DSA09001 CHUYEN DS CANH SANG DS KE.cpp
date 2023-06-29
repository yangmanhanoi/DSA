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
        vector<int> Ke[n + 5];
        while(m--)
        {
            int x, y; cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        for(int i = 1; i <= n; i++)
        {
            cout << i << ": ";
            for(auto &x : Ke[i]) cout << x << ' ';
            cout << endl;
        }
    }
    return 0;
}