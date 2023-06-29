#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t;cin.ignore(); while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        string s;
        getline(cin, s);
        stack<string> st;
        stringstream ss(s);
        while(ss >> s)
        {
            st.push(s);
        }
        while(!st.empty())
        {
            cout << st.top() << ' ';
            st.pop();
        }
        cout << endl;
    }
    return 0;
}