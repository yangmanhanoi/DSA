#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
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
        if(n % 2 != 0)
        {
            if(n == 3) cout << "NO\n";
            else
            {
                cout << "YES\n";
                int chan = n/2, le = chan + 1;
                chan--; le--;
                for(int i = 1; i <= n /2; i++)
                {
                    cout << -chan << ' ' << le << ' ';
                }
                cout << -chan << endl;
            }
        }
        else
        {
            cout << "YES\n";
            for(int i = 1; i <= n; i++)
            {
                if(i % 2 == 0) cout << -1 << ' ';
                else cout << 1 << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}