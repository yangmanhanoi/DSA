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
map<char, int> m;
int main()
{
    faster()
        m['+'] = m['-'] = 1;
    m['*'] = m['/'] = 2;
    m['*'] = 3;
    test()
    {
        string s;
        cin >> s;
        string res = "";
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if ('A' <= s[i] <= 'Z')
                res += s[i];
            else if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                while (!st.empty() and st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() and m[st.top()] >= m[s[i]])
                {
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        cout << res << endl;
    }
    return 0;
}