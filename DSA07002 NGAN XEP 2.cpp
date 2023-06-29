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
    stack<int> st;
    test()
    {
        int n;
        string s; cin >> s;
        if(s == "PUSH")
        {
            cin >> n;
            st.push(n);
        }
        else if(s == "POP")
        {
            if(!st.empty()) st.pop();
        }
        else
        {
            if(!st.empty()) cout << st.top() << endl;
            else
            {
                cout << "NONE" << endl;

            }
        }
    }
    return 0;
}