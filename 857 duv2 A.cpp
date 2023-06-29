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
        int a[n + 5];
        int cntX = 0, cntY = 0;
        FOR(i, 1, n)
        {
            cin >> a[i];
            if(a[i] > 0) cntX++;
            else cntY++;
        }
        for(int i = 1; i <= n; i++)
        {
            if(i <= cntX) cout << i << ' ';
            else cout << cntX - (i - cntX) << ' '; 
        }
        cout << endl;
        for(int i = 0; i < cntY; i++)
        {
            cout << "1 0 ";
        }
        if(cntX - cntY > 0)
        {
            for(int i = 1; i <= (cntX - cntY); i++) cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}