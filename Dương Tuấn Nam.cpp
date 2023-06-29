#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, ok = 1;
string s = "";
vector<string> vs;
void ktao()
{
    for(int i = 0; i < n; i++)
    {
        s += "0";
    }
}
void sinh()
{
    int i = n - 1;
    while(i >= 0 and s[i] == '1')
    {
        --i;   
    }
    if(i == -1) ok = 0;
    else
    {
        s[i] = '1';
        for(int j = i + 1; j < n; j++)
        {
            s[j] = '0';
        }
    }
}
int check()
{
    int l = s.size() / 2;
    for(int i = 0; i <= l; i++)
    {
        if(s[i] != s[s.size() - 1 - i]) return 0;
    }
    return 1;
}
int main()
{
    cin >> n;
    ktao();
    vs.push_back(s);
    while(ok)
    {
        sinh();
        if(check())
        {
            vs.push_back(s);
        }
    }
    for(int i = 0; i < vs.size() - 1; i++)
    {
        for(int j = 0; j < vs[i].size(); j++)
        {
            cout << vs[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}