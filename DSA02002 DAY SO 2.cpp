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
        int a[n];
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            q.push(a[i]);
        }
        vector<string> vs;
        for(int i = 1; i <= n; i++)
        {
            string s = "";
            for(int j = n - i; j >= 0; j--)
            {
                int x = q.front();
                s += to_string(x);
                if(j > 0) s += ' ';
                q.pop();
                x += q.front();
                if(j > 0) q.push(x);
            }
            vs.push_back(s);
        }
        for(int i = vs.size() - 1; i >= 0; i--)
        {
            cout << "[" << vs[i] << "] ";
        }
        cout << endl;
    }
    return 0;
}