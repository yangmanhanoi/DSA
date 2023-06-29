#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        string s; cin >> s;
        stack<string> st;
        string infix = "";
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if('A' <= s[i] and s[i] <= 'Z')
            {
                st.push(string(1, s[i]));
            }
            else
            {
                string s1, s2, tmp = "";
                if(!st.empty())
                {
                    s1 = st.top();
                    st.pop();
                }
                if(!st.empty())
                {
                    s2 = st.top();
                    st.pop();
                }
                tmp = "(" + s1 + s[i] + s2 + ")";
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}