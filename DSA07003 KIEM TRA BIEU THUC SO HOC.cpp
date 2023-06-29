#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t;cin.ignore(); while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool check(string s)
{
    stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ' or ('a' <= s[i] and s[i] <= 'z')) continue;
        if(s[i] == ')')
        {
            if(st.top() == '(') return 1;
            else
            {
                while(!st.empty() and st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
        else st.push(s[i]);
    }
    return 0;
}
int main()
{
    faster()
    test()
    {
        string s; 
        getline(cin, s);
        if(check(s)) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    return 0;
}