#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int ok = 1;
void sinh(string &s)
{
    int i = s.size() - 1;
    while(i >= 0 and s[i] == '1')
    {
        --i;
    }
    if(i == -1) ok = 0;
    else
    {
        s[i] = '1';
        for(int j = i + 1; j < s.size(); j++)
        {
            s[j] = '0';
        }
    }
}
int main()
{
    faster();
    test()
    {
        string s; cin >> s;
        sinh(s);
        cout << s << endl;
    }
}