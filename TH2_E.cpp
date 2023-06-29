#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}
int main()
{
    faster()
    int n; cin >> n;
    vector<pair<int,int>> vs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vs[i].second >> vs[i].first;
    }
    sort(vs.begin(), vs.end());
    unordered_map<int,int> mp;
    ll ans = 0;
    for(auto &i : vs)
    {
        while(mp[i.second] and i.second >= 1) i.second--;
        ans += i.first;
        mp[i.second]++;
    }
    cout << ans << endl;
    return 0;
}