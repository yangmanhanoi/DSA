#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
        stack<char> st;
        int cnt = 0;
        for(char i : s)
        {
            if(st.empty())
            {
                st.push(i);
                continue;
            }
            if(i == '(') st.push(i);
            else
            {
                if(st.top() == '(')
                {
                    cnt += 2;
                    st.pop();
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}