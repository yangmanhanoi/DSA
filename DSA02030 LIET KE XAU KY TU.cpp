#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
char c;
int n, l;
string s = "";
void Try(char i)
{
    if(s.size() == n)
    {
        cout << s;
        cout << endl;
        return;
    }
    for(char j = i; j <= c; j++)
    {
        s += j;
        Try(j);
        s.pop_back();
    }
}
int main()
{
    faster()
    cin >> c >> n;
    l = (int)c - 'A';
    l++;
   // cout << l;
    Try('A');
    return 0;
}