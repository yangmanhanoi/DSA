#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test()    \
    int t;        \
    cin >> t;     \
    cin.ignore(); \
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
        string s;
        int n; cin >> n;
        getline(cin, s);
        stack<ll> st;
        for (int i = 0; i < s.size(); i++)
        {
            string tmp = "";
            while (isdigit(s[i]) or s[i] == ' ' or (i < n - 1 and (s[i] == '-' and isdigit(s[i + 1]))))
            {
                tmp += s[i];
                ++i;
            }
            stringstream ss(tmp);
            while (ss >> tmp)
            {
                ll x = stoll(tmp);
                st.push(x);
            }
            ll x1 = 0, x2 = 0, res;
            if (!st.empty())
            {
                x1 = st.top();
                st.pop();
            }
            if (!st.empty())
            {
                x2 = st.top();
                st.pop();
            }
            if (s[i] == '*')
                res = x1 * x2;
            else if (s[i] == '+')
                res = x1 + x2;
            else if (s[i] == '-')
                res = x2 - x1;
            else if (s[i] == '/')
                res = x2 / x1;
            st.push(res);
        }
        cout << st.top() << endl;
    }
    return 0;
}