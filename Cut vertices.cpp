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
int n;
int a[1005][1005];
int visited[1005] = {}, low[1005] = {}, num[1005] = {}, par[1005] = {}, cnt = 0;
vector<int> v;
void DFS(vector<int> Ke[], int u)
{
    int countChild = 0;
    num[u] = low[u] = cnt++;
    visited[u] = 1;
    for(auto i : Ke[u])
    {
        if(i != par[u])
        {
            if(!visited[i])
            {
                countChild++;
                DFS(Ke, i);
                low[u] = min(low[i], low[u]);
            }
            else
            {
                low[u] = min(num[i], low[u]);
                if(low[u] > num[i]) v.push_back(u);
            }
        }
    }
    if(u == 1 and countChild == 1) v.push_back(1);
}
int main()
{
    faster()
    cin >> n;
    vector<int> Ke[n + 5];
    F(i, 1, n)
    {
        F(j, 1, n)
        {
            cin >> a[i][j];
            if(a[i][j])
            {
                Ke[i].push_back(j);
                Ke[j].push_back(i);
            }
        }
    }
    DFS(Ke, 1);
    for(auto i : v) cout << i << endl;
}