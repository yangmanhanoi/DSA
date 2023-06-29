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
        int n, k; cin >> n >> k;
        int a[n + 5];
        int x = n;
        for(int i = 1; i <= n; i++)
        {
            if(i % k != 0)
            {
                a[i] = x--;
            }
        }
        x = 1;
        for(int i = k; i <= n; i += k)
        {
            a[i] = x++;
        }
        FOR(i, 1, n) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}