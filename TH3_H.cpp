#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test()    \
    int t;        \
    cin >> t;     \
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
        vector<string> vs(n);
        for (int i = 0; i < n; i++)
            cin >> vs[i];
      //   for(auto &i : vs) cout << i << '_';
        stack<ll> st;
        for (int i = 0; i < n; i++)
        {
            if (vs[i] != "+" and vs[i] != "-" and vs[i] != "*" and vs[i] != "/")
            {
                ll x = 0;
                if(vs[i][0] == '-')
                {
                    for(int j = 1; j < vs[i].size(); j++)
                    {
                        x = (x *10) + (vs[i][j] - '0');
                    }
                    x = -x;
                }
                else
                {
                    for(int j = 0; j < vs[i].size(); j++)
                    {
                        x = (x *10) + (vs[i][j] - '0');
                    }
                }
               // cout << x << ' ';
                st.push(x);
            }
            else
            {
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
                if (vs[i] == "*")
                    res = x1 * x2;
                else if (vs[i] == "+")
                    res = x1 + x2;
                else if (vs[i] == "-")
                    res = x2 - x1;
                else if (vs[i] == "/")
                    res = x2 / x1;
                st.push(res);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}