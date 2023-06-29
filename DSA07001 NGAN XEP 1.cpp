#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    string s; int n;
    stack<int> st;
    while(cin >> s)
    {
        
        if(s == "push")
        {
            cin >> n;
            st.push(n);
        }
        else if(s == "pop")
        {
            if(!st.empty()) st.pop();
        }
        else
        {
            if(!st.empty())
            {
                stack<int> res;
                res = st;
                stack<int> tmp;
                while(!st.empty())
                {
                    tmp.push(st.top());
                    st.pop();
                }
                st = res;
                while(!tmp.empty())
                {
                    cout << tmp.top() << ' ';
                    tmp.pop();
                }
                cout << endl;
            }  
            else
            {
                cout << "empty";
                break;
            }
        }
    }
    return 0;
}