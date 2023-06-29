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
        int a[n + 5];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        string s1 = "", s2 = "";
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0) s1 += to_string(a[i]);
            else s2 += to_string(a[i]);
        }
        cout << stoll(s1) + stoll(s2) << endl;
    }
    return 0;
}