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
        int a[n + 5][n + 5];
        int s = 1, e = n * n;
        for(int i = 1; i <= n; i++)
        {
            if(i % 2 == 1)
            {
                for(int j = 1; j <= n; j++)
                {
                    if(j % 2 == 1) a[i][j] = s++;
                    else a[i][j] = e--;
                }
            }
            else
            {
                for(int j = n; j >= 1; j--)
                {
                    if(j % 2 == 1) a[i][j] = e--;
                    else a[i][j] = s++;
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}