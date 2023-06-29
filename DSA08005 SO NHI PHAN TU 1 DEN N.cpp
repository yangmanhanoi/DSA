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
        int n; cin >> n;
        queue<string> q;
        q.push("1");
        while(n--)
        {
            string top = q.front();
            cout << top << ' ';
            q.pop();
            q.push(top + "0");
            q.push(top + "1");
        }
        cout << endl;
    }
    return 0;
}