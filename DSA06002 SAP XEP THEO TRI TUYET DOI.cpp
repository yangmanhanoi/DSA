#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first < b.first) return 1;
    else if(a.first > b.first) return 0;
    else return a.second < b.second;
}
int main()
{
    faster();
    test()
    {
        int n, x; cin >> n >> x;
        int a[n], b[n];
        vector<pair<int,int>> vs;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = abs(a[i] - x);
            vs.push_back({b[i], i});
        }
        sort(vs.begin(),vs.end(), cmp);
        for(auto &i : vs) cout << a[i.second] << ' ';
        cout << endl; 
    }
    return 0;
}