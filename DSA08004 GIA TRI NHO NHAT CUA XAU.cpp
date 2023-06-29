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
        string s; cin >> s;
        priority_queue<pair<ll, char>> pq;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            pq.push({m[s[i]], s[i]});
        }
        int cnt = 0;
        while(cnt < n)
        {
            pq.pop();
            cnt++;
        }
        ll ans = 0;
        m.clear();
        while(!pq.empty())
        {
            if(m[pq.top().second] == 0)
            {
                ans += pow(pq.top().first, 2);
                m[pq.top().second]++;
            }
          //  cout << pq.top().first << ' ' << pq.top().second << endl;
            pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}