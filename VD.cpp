#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n;
string s = "CBA";
vector<string> vs;
string res = "";
unordered_map<char, int> mp;
void Try(int i, int cnt = 0)
{
    if(res.size() > n) return;
    if(res.size() >= 3)
    {
        if(cnt == 3)
        {
            if(mp['A'] <= mp['B'] and mp['B'] <= mp['C']) vs.push_back(res);
        }
    }
    for(int j = 2; j >= 0; j--)
    {
        res += s[j];
        mp[s[j]]++;
        Try(i + 1, cnt + (mp[s[j]] == 1));
        mp[s[j]]--;
        res.pop_back();
    }
}
bool cmp(string a, string b)
{
    if(a.size() < b.size()) return 1;
    else if(a.size() > b.size()) return 0;
    else return a < b;
}
int main()
{
    faster()
    cin >> n;
    Try(1);
    sort(vs.begin(), vs.end(), cmp);
    for(auto &i : vs) cout << i << endl;
    return 0;
}