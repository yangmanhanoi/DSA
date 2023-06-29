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
    deque<int> dq;
    string s;
    int x;
    test()
    {
        cin >> s;
        if(s == "PUSHBACK")
        {
            cin >> x;
            dq.push_back(x);
        }
        else if( s == "PUSHFRONT")
        {
            cin >> x;
            dq.push_front(x);
        }
        else if(s == "POPBACK")
        {
            if(!dq.empty()) dq.pop_back();
        }
        else if(s == "POPFRONT")
        {
            if(!dq.empty()) dq.pop_front();
        }
        else if(s == "PRINTFRONT")
        {
            if(!dq.empty()) cout << dq.front() << endl;
            else cout << "NONE\n";
        }
        else if(s == "PRINTBACK")
        {
            if(!dq.empty()) cout << dq.back() << endl;
            else cout << "NONE\n";
        }
    }
    return 0;
}