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
int a[1005][1005];
int w[1005], visited[105];
int n, u;
int Prim(int u, vector<pair<int, int>> Ke[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, u});
    w[u] = 0;
    while (!pq.empty())
    {
        pair<int,int> top = pq.top();
        pq.pop();
        int dinh = top.second, trongso = top.first;
        for(auto &i : Ke[dinh])
        {
            if(!visited[i.first])
            {
                if(i.second < w[i.first])
                {
                    pq.push({i.second, i.first});
                    w[i.first] = i.second;
                }
            }
        }
        visited[top.second] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += w[i];
    return ans;
}
int main()
{
    faster()
    cin >> n >> u;
    vector<pair<int, int>> Ke[1005];
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < 1000; i++) w[i] = 1e9;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] != 0 and a[i][j] != 1e9)
            {
                Ke[i].push_back({j, a[i][j]});
                Ke[j].push_back({i, a[i][j]});   
            }
        }
    }
    cout << Prim(u, Ke) << endl;
    return 0;
}