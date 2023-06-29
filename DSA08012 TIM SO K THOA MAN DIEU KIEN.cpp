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
inline bool check(string &s)
{
    int f[10] = {};
    for(char &i : s)
    {
        ++f[i - '0'];
        if(f[i - '0'] > 1) return 0;
    }
    return 1;
}
int main()
{
    faster()
    queue<string> q;
    vector<ll> vs;
    for (int i = 1; i <= 5; i++)
    {
        q.push(to_string(i));
        vs.push_back(i);
    }
    int ok = 1;
    while (ok)
    {
        string top = q.front();
        q.pop();
        for(int i = 0; i <= 5; i++)
        {
            string tmp = "";
            tmp += top + to_string(i);
            if(check(tmp))
            {
                vs.push_back(stoll(tmp));
                q.push(tmp);
            }
            if(stoll(tmp) > 1e6)
            {
                ok = 0;
                break;
            }
        }
    }
    test()
    {
        ll s1, s2;
        cin >> s1 >> s2;
        int pos1 = lower_bound(vs.begin(), vs.end(), s1) - vs.begin();
        int pos2 = lower_bound(vs.begin(), vs.end(), s2) - vs.begin();
        if(vs[pos2] > s2) pos2--;
        cout << pos2 - pos1 + 1 << endl;
    }
    return 0;
}