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
    queue<string> q;
    vector<ll> vs;
    q.push("1");
    vs.push_back(1);
    while(vs.back() < 1e18)
    {
        string top = q.front();
        q.pop();
        q.push(top + "0");
        q.push(top + "1");
        vs.push_back(stoll(top + "0"));
        vs.push_back(stoll(top + "1"));
    }
    test()
    {
        ll n; cin >> n;
        ll pos = upper_bound(vs.begin(), vs.end(), n) - vs.begin();
        cout << pos << endl;
    }
    return 0;
}