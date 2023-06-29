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
        int q, x, y; cin >> q;
        queue<int> qp;
        while(q--)
        {
            cin >> x;
            if(x == 3)
            {
                cin >> y;
                qp.push(y);
            }
            else if(x == 1) cout << qp.size() << endl;
            else if(x == 2)
            {
                if(!qp.empty()) cout << "NO\n";
                else cout << "YES\n";
            }
            else if(x == 4)
            {
                if(!qp.empty()) qp.pop();
            }
            else if(x == 5)
            {
                if(!qp.empty()) cout << qp.front() << endl;
                else cout << -1 << endl;
            }
            else
            {
                if(!qp.empty()) cout << qp.back() << endl;
                else cout << -1 << endl;
            }
        }
    }
    return 0;
}