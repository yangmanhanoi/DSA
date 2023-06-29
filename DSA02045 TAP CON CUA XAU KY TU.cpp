#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n;
string s;
string str = "";
vector<string> vs;
void Try(int i)
{
    if(i > n) return;
    if(str.size() > 0)
    {
        vs.push_back(str);
    }
    for(int j = i; j < n; j++)
    {
        str += s[j];
        Try(j + 1);
        str.pop_back();
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> s;
        Try(0);
        sort(vs.begin(), vs.end());
        for(auto &i : vs) cout << i << ' ';
        cout << endl;
        str = "";
        vs.clear();
    }
    return 0;
}