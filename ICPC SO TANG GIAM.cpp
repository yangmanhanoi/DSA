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
        int idx = 0, check = 1;
        string str = "";
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] <= s[i + 1] and check == 1)
            {
                str += s[i];
                idx = i;
            }
            else if(s[i] >= s[i + 1])
            {
                str += s[i];
                idx = i;
                check = 0;
            }
            else if(s[i] < s[i + 1] and check == 0)
            {
                str += s[i];
                idx = i;
                break;
            }
        }
        if(idx == s.size() - 2)
        {
            if(s[idx] < s[idx + 1]) str += s[idx];
            else str += s[idx + 1];
        }
        else
        {
            while(str.size() < s.size())
            {
                str += s[idx];
            }   
        }
        cout << str << endl;
    }
    return 0;
}