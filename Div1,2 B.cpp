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
#define all(x) (x).begin(), (x).end()
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    faster()
    test()
    {
        // int n, m, k; cin >> n >> m >> k;
        // vi v(m);
        // F(i, 0, m) cin >> v[i];
        // sort(all(v), cmp);
        // int segment = n / k;
        // int rem = n % k;
        // int cnt = 0;
        // int check = 1;
        // for(int i : v)
        // {
        //     if(i > segment)
        //     {
        //         if(i == segment + 1)
        //         {
        //             cnt++;
        //         }
        //         else
        //         {
        //             check = 0;
        //             break;
        //         }
        //     }
        // }
        // if(check)
        // {
        //     if(cnt > rem) check = 0;
        // }
        // if(check) cout << "YES\n";
        // else cout << "NO\n";
        int n; cin >> n;
        vi v(n);
        F(i, 0, n) cin >> v[i];
        int a = v[n - 1], b = v[n - 1];
        F(i, 0, n)
        {
            a |= v[i];
            b &= v[i];
        }
        cout << a - b << endl;
    }
    return 0;
}