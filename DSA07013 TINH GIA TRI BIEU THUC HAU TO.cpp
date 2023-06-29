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
        ll ans = 0;
        stack<ll> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                st.push(s[i] - '0');
            }
            else
            {
                ll x1 = 0, x2 = 0, tmp;
                if(!st.empty())
                {
                    x1 = st.top();
                    st.pop();
                }
                if(!st.empty())
                {
                    x2 = st.top();
                    st.pop();
                }
                if(s[i] == '*') tmp = x1 * x2;
                else if(s[i] == '+') tmp = x1 + x2;
                else if(s[i] == '-') tmp = x2 - x1;
                else if(s[i] == '/') tmp = x2 / x1;
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}