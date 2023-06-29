#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
string a = "ABCDEFGH";
string s = "";
int n;
bool check()
{
    for(int i = 1; i < s.size() - 1; i++)
    {
        if((s[i] == 'E' and s[i + 1] != 'A' and s[i - 1] != 'A')) return 0;
        if((s[i] == 'A' and s[i + 1] != 'E' and s[i - 1] != 'E')) return 0;
    }
    return 1;
}
void print()
{
    cout << s << endl;
}
int visited[8] = {};
void Try(int i)
{
    if(s.size() == n)
    {
        if(check()) print();
        //cout << s << endl;
        return;
    }
    for(int j = 0; j < n; j++)
    {
        if(!visited[j])
        {
            s += a[j];
            visited[j] = 1;
            Try(i + 1);
            s.pop_back();
            visited[j] = 0;
        }
    }
}
int main()
{
    faster();
    char c; cin >> c;
    n = (int)c - (int)'A' + 1;
    Try(0);
    return 0;
}