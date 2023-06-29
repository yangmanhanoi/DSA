#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k;
string s="";
void Try(int i)
{
    if(s.size() == n)
    {
        cout << s;
        return;
    }
    for(int j = i; j <= n; j++)
    {
        s += to_string(j);
        Try(j + 1);
        s.pop_back();
    }
}
int main()
{
    faster()
    cin >> n, k;
    Try(1);
    return 0;
}