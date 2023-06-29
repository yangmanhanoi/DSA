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
        int ans = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(') st.push(i);
            else
            {
                st.pop();
                if(st.empty()) st.push(i);
                else ans = max(ans, i - st.top());
            }
        }
        cout << ans << endl;
    }
    return 0;
}