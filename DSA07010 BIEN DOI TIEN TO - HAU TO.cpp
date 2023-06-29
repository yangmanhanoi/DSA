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
string preToin(string s)
{
    stack<string> st;
    string infix = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ('A' <= s[i] and s[i] <= 'Z')
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string s1, s2, tmp = "";
            if (!st.empty())
            {
                s1 = st.top();
                st.pop();
            }
            if (!st.empty())
            {
                s2 = st.top();
                st.pop();
            }
            tmp = "(" + s1 + s[i] + s2 + ")";
            st.push(tmp);
        }
    }
    return st.top();
}
string inTopost(string s)
{
    stack<char> st;
    string postfix = "";
    for(int i = 0; i < s.size(); i++)
    {
        if ('A' <= s[i] and s[i] <= 'Z')
        {
            postfix += string(1, s[i]);
        }
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')')
        {
            while(!st.empty() and st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() and m[s[i]] <= m[st.top()])
            {
                postfix += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main()
{
    faster()
    m['+'] = m['-'] = 1; m['*'] = m['/'] = 2; m['^'] = 3;
        test()
    {
        string s;
        cin >> s;
        string inFix = preToin(s);
      //  cout << inFix << endl;
        string postFix = inTopost(inFix);
        cout << postFix << endl;
    }
    return 0;
}