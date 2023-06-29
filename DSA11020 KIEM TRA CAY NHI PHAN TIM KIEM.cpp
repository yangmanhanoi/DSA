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
        vector<int> a(n);
        set<int> s;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        } 
        if(is_sorted(a.begin(), a.end()) and s.size() == n) cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}