#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n = 3;
string s = "";
vector<string> vs;
vector<string> res;
void print()
{
    string tmp = s;
    tmp.insert(2, "/");
    tmp.insert(5, "/");
    cout << tmp << endl;
}
void Try(int i)
{
    if(s.size() == n)
    {
        vs.push_back(s);
        return;
    }
    for(int j = 0; j <= 2; j += 2)
    {
        s += to_string(j);
        Try(i + 1);
        s.pop_back();
    }
}
int main()
{
    faster();
    res.push_back("02");
    res.push_back("20");
    res.push_back("22");
    Try(0);
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < vs.size(); j++)
        {
            cout << res[i] << "/02/2" << vs[j] << endl;
        }
    }
    return 0;
}