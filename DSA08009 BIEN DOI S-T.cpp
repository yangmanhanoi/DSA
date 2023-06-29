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
        ll s, t;
        cin >> s >> t;
        int trace[200005] = {};
        unordered_map<ll, int> m;
        queue<ll> q;
        q.push(s);
        m[s]++;
        while(!q.empty())
        {
            ll top = q.front();
            q.pop();
            if(m[top - 1] == 0)
            {
                q.push(top - 1);
                m[top - 1] ++;
                trace[top - 1] = trace[top] + 1;
                if(top - 1 == t) break;
            }
            if(m[top * 2] == 0)
            {
                q.push(top *2);
                m[top * 2]++;
                trace[top * 2] = trace[top] + 1;
                if(top * 2 == t) break;
            }
        }
        cout << trace[t] << endl; 
    }
    return 0;
}