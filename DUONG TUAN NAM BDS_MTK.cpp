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
int visited[1005] = {};
void bfs(vector<int> Ke[], int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int top = q.front();
        cout << top << ' ';
        q.pop();
        for(auto &i : Ke[top])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    faster()
    cin >> n;
    vector<int> Ke[n + 5];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            if(a[i][j])
            {
                Ke[i].push_back(j);
                Ke[j].push_back(i);
            }
        }
    }
    
    bfs(Ke, 1);
    return 0;
}