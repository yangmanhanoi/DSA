#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second > b.second) return 1;
    else if(a.second < b.second) return 0;
    else return a.first < b.first;
}
int main()
{
    faster();
    test()
    {
        int n; cin >> n;
        int a[n]; unordered_map<int,int> m;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        vector<pair<int,int>> vs;
        for(auto &i : m) vs.push_back({i.first, i.second});
        sort(vs.begin(),vs.end(),cmp);
        for(auto &i : vs)
        {
            while (i.second > 0)
            {
                cout << i.first << ' ';
                i.second--;
            }  
        }
        cout << endl;
    }
    return 0;
}