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
    test()
    {
        int n; cin >> n;
        queue<string> q;
        vector<string> vs;
        q.push("6");
        q.push("8");
        vs.push_back("6");
        vs.push_back("8");
        while(vs.back().size() <= n)
        {
            string top = q.front();
            q.pop();
            q.push(top + "6");
            q.push(top + "8");
            vs.push_back(top + "6");
            vs.push_back(top + "8");
        }
        cout << vs.size() - 2 << endl;
        for(int i = vs.size() - 3; i >= 0;i--) cout << vs[i] << ' ';
        cout << endl;
    }
    return 0;
}