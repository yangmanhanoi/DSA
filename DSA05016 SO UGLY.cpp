#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
const int MOD = 1e9 + 7;
int a[3] = {2, 3, 5};
int main()
{
    faster();
    unordered_map<ll, int> mp;
    vector<ll> vs;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(5);
    while (vs.size() < 10000)
    {
        ll tmp = pq.top();
        for (auto &i : a)
        {
            if (mp[tmp * i] == 0)
            {
                pq.push(tmp * i);
                mp[tmp * i]++;
            }
        }
        vs.push_back(tmp);
        pq.pop();
    }
    test()
    {
        int n;
        cin >> n;
        cout << vs[n - 2] << endl;
    }
    return 0;
}