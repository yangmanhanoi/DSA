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
string inTopre(string s)
{
    string res = "";
    stack<char> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isalpha(s[i]))
            res += s[i];
        else if (s[i] == ')')
            st.push(s[i]);
        else if (s[i] == '(')
        {
            while (!st.empty() and st.top() != ')')
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
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    faster()
        m['+'] = m['-'] = 1;
    m['*'] = m['/'] = 2;
    m['^'] = 3;
    test()
    {
        string s;
        cin >> s;
        string tmp = postToin(s);
      //  cout << tmp << endl;
        cout << inTopre(tmp) << endl;
    }
    return 0;
}