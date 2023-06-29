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
    int n; cin >> n;
    int a[n];
    vector<int> b,c;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i % 2 == 0) c.push_back(a[i]);
        else b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    sort(c.begin(),c.end(), greater<int>());
    for(int i = 0; i < c.size(); i++)
    {
        cout << b[i] << ' ' << c[i] << ' ';
    }
    if(n % 2 == 1) cout << b[b.size() - 1];
    return 0;
}