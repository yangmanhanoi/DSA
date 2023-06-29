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
        int n, m; cin >> n >> m;
        int a[n], b[m];
        map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
            mp[b[i]]++;
        }
        for(auto &i : mp)
        {
            while(i.second > 0)
            {
                cout << i.first << ' ';
                i.second--;
            }
        }
        cout << endl;
    }
    return 0;
}