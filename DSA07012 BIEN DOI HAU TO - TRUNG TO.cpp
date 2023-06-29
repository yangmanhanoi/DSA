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
string postToin(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
            st.push(string(1, s[i]));
        else
        {
            string x1, x2, tmp = "";
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
            tmp = "(" + x2 + s[i] + x1 + ")";
            st.push(tmp);
        }
    }
    return st.top();
}
int main()
{
    faster()
    test()
    {
        string s; cin >> s;
        cout << postToin(s) << endl;
    }
    return 0;
}