#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool cmp(pair<int, int> a, pair<int,int> b)
{
    if(a.first < b.first) return 1;
    else if(a.first > b.first) return 0;
    else return a.second < b.second;
}
int main()
{
    faster()
    int n; cin >> n;
    cin.ignore();
    vector<pair<int,int>> vs;
    set<string> ms;
    int idx = 1;
    int f[55][55] = {};
    while(n--)
    {
        string s; getline(cin, s);
        stringstream ss(s);
        while(ss >> s)
        {
            int x = stoi(s);
            if(!f[idx][x] and !f[x][idx])
            {
                vs.push_back({idx, x});
                f[idx][x] = f[x][idx] = 1;
            }
        }
        idx++;
    }
    sort(vs.begin(), vs.end(), cmp);
    for(auto &i : vs) cout << i.first << ' ' << i.second << endl;
    return 0;
}