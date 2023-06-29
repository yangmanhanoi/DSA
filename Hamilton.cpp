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
int n, st;
int visited[105] = {}, par[105] = {};
void checkAndPrint(int x)
{
    vector<int> v;
    v.push_back(st);
    while(x != 0)
    {
        v.push_back(x);
        x = par[x];
    }
    if(v.size() != n + 1) return;
    reverse(v.begin(), v.end());
    for(auto i : v) cout << i << ' ';
    cout << endl;
}
void Hamilton(vector<int> Ke[], int u)
{
    visited[u] = 1;
    for(auto i: Ke[u])
    {
        if(!visited[i])
        {
            par[i] = u;
            Hamilton(Ke, i);
            visited[i] = 0;
        }
        else if(visited[i] and i == st)
        {
            checkAndPrint(u);
        }
    }
}
int main()
{
    faster()
    int u;
    cin >> n >> u;
    st = u;
    int a[n + 5][n + 5];
    vector<int> Ke[n + 5];
    FOR(i ,1 , n)
    {
        FOR(j, 1, n)
        {
            cin >> a[i][j];
            if(a[i][j])
            {
                Ke[i].push_back(j);
            }
        }
    }
    Hamilton(Ke, u);
    return 0;
}