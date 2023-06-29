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
        cout << s << endl;
        return;
    }
    for(int j = 0; j <= 1; j++)
    {
        s += to_string(j);
        Try(i + 1);
        s.pop_back();
    }
}
int main()
{
    faster()
    cin >> n;
    Try(1);
    return 0;
}
