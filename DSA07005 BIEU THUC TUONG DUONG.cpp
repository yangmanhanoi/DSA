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
        stack<char> st1, st2;
        s = '+' + s;
        st2.push('+');
        for(char i : s)
        {
            if(isalpha(i)) st1.push(i);
            else
            {
                if(i == '+' or i == '-')
                {
                    if(st2.top() == '+') st1.push(i);
                    else
                    {
                        if(i == '+') st1.push('-');
                        else st1.push('+');
                    }
                }
                else if(i == '(') st2.push(st1.top());
                else st2.pop();
            }
        }
        string ans = "";
        while(st1.size() > 1)
        {
            ans = st1.top() + ans;
            st1.pop();
        }
        cout << ans << endl;
    }
    return 0;
}