#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
vector<int> vs;
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int a[n];
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            q.push(a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            cout << "[";
            for(int j = n - i; j >= 0; j--)
            {
                int x = q.front();
                cout << x;
                if(j > 0) cout << ' ';
                q.pop();
                x += q.front();
                if(j > 0) q.push(x);
            }
            cout << "]\n";
        }
    }
    return 0;
}