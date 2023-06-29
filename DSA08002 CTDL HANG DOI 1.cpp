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
    queue<int> q;
    test()
    {
        string s;
        int x;
        cin >> s;
        if(s == "PUSH")
        {
            cin >> x;
            q.push(x);
        }
        else if(s == "POP")
        {
            if(!q.empty()) q.pop();
        }
        else
        {
            if(!q.empty()) cout << q.front() << endl;
            else cout << "NONE\n";
        }
    }
    return 0;
}