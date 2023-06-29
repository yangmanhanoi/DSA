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
int main()
{
    faster()
    test()
    {
        int n;
        cin >> n;
        queue<string> q;
        q.push("0");
        q.push("1");
        set<int> s;
        s.insert(0);
        while (s.size() <= n/2 + 1)
        {
            string top = q.front();
            if(top.size() > n/2) break;
            q.pop();
            cout << top;
            q.push(top + "0");
            q.push(top + "1");
            s.insert(top.size() + 1);
            reverse(top.begin(), top.end());
            cout << top << ' ';
        }
        cout << endl;
    }
}