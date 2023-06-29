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
    vector<string> vs;
    int n, x; cin >> n;
    multiset<int> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> x; s.insert(x);
        string str = "";
        for(auto &j : s) str += to_string(j) + " ";
        vs.push_back(str);
    }
    for(int i = vs.size() - 1; i >= 0; i --)
    {
        cout << "Buoc " << i << ": ";
        cout << vs[i] << endl;
    }
    return 0;
}