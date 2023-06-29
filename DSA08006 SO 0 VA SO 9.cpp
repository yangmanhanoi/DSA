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
    unordered_map<string, int> mp;
    vector<string> vs;
    q.push("9");
    mp["9"]++;
    vs.push_back("9");
    while(vs.size() <= 10000)
    {
        string top = q.front();
        q.pop();
        if(mp[top + "0"] == 0)
        {
            q.push(top + "0");
            mp[top + "0"]++;
            vs.push_back(top + "0");
        }
        if(mp[top + "9"] == 0)
        {
            q.push(top + "9");
            mp[top + "9"]++;
            vs.push_back(top + "9");
        }
    }
    test()
    {
        int n; cin >> n;
        int i = 0;
        while(stoll(vs[i]) % n != 0)
        {
            i++;
        }
        cout << vs[i] << endl;
    }
    return 0;
}