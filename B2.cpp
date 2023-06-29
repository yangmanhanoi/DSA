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
ll f[50] = {};
ll binSearch(int n, int k)
{
    if(k == 0) return 0;
    if(n == 0 and k == 1) return 1;
    else if(n == 1 and k == 1) return 0;
    if(k <= f[n - 1]) return binSearch(n - 1, k);
    else
    {
        int cntL = binSearch(n - 1, f[n - 1]);
        int cntR = binSearch(n - 2, k - f[n - 1]);
        return cntL + cntR;
    } 
}
int main()
{
    faster()
    f[0] = f[1] = 1;
    for(int i = 2; i < 50; i++) f[i] = f[i - 1] + f[i - 2];
    test()
    {
        int n, k; cin >> n >> k;
        cout << binSearch(n, k) << endl;
    }
    return 0;
}