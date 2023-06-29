#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t; while(t--)
    {
        string s; cin >> s;
        stack<char> S;
        int check = 1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' or s[i] == '[' or s[i] == '{')
            {
                S.push(s[i]);
            }
            else
            {
                if(S.empty() or (s[i] == ')' and S.top() != '(') or (s[i] == ']' and S.top() != '[') or (s[i] == '}' and S.top() != '{'))
                {
                    check = 0;
                    break;
                }
                S.pop();
            }
        }
        if(check == 0) cout << "NO\n";
        else
        {
            if(!S.empty()) cout << "NO\n";
            else cout << "YES\n";
        } 
    }
    return 0;
}