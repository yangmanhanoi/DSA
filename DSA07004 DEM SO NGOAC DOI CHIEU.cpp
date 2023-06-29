#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster();
    test()
    {
        string s; cin >> s;
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(') st.push('(');
            else if(s[i] == ')' and !st.empty() and st.top() == '(') st.pop();
            else st.push(')');
        }
        int ans = 0;
        while(!st.empty())
        {
            if(st.top() == '(')
            {
                if(!st.empty()) st.pop();
                if(!st.empty() and st.top() == '(') ans++;
                else if(!st.empty() and st.top() == ')') ans+= 2;
                if(!st.empty()) st.pop();
            }
            else
            {
                if(!st.empty()) st.pop();
                if(!st.empty() and st.top() == ')') ans ++;
                if(!st.empty()) st.pop();
            }
        }
        cout << ans << endl;
    }
    return 0;
}