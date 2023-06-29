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
        getline(cin, s);
        s = '+' + s;
        string res = "";
        stack<char> st, st1;
        int flag = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-' and s[i + 1] == '(')
            {
                i++;
                st.push('-');
                st.push('(');
            }
            else
            {
                if (s[i] != ' ' or (s[i] == '+' and s[i + 1] != '('))
                    st.push(s[i]);
                if (s[i] == ')')
                {
                    while (!st.empty())
                    {
                        st1.push(st.top());
                        st.pop();
                    }
                    if(st1.top() == '(') flag = 1;
                    string tmp = "";
                    while(!st1.empty())
                    {
                        tmp += st1.top();
                        st1.pop();
                    }
                    if(flag) res += ')';
                    flag = 0;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}