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
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    faster()
    test()
    {
        int n, m; cin >> n >> m;
        int a[n + 1], b[m + 1];
        priority_queue<ll, vector<ll>, greater<>> pq;
        FOR(i, 1, n)
        {
            cin >> a[i];
            pq.push(a[i]);
        }
        FOR(i, 1, m)
        {
            cin >> b[i];
        }
       // sort(b + 1, b + m + 1);
        FOR(i, 1, m)
        {
            pq.pop();
            pq.push(b[i]);
        }
        ll sum = 0;
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        cout << sum << endl;
    }
    return 0;
}