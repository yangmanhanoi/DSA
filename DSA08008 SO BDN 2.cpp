#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll n;

bool check(string &s)
{
    ll tmp = 0;
    for(char &i : s)
    {
        tmp = tmp * 10 + i - '0';
        tmp %= n;
    }
    return !tmp;
}

string findNum()
{
    queue<string> q;
    q.push("1");
    string s;
    while(q.size())
    {
        s = q.front();
        q.pop();
        if(check(s)) return s;
        q.push(s + "0");
        q.push(s + "1");
    }
    return "";
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << findNum() << endl;
    }
    return 0;
}