#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int visited[200005] = {}, sum[200005] = {}, val[200005] = {};
void dfs(vector<int> Ke[], int u)
{
    visited[u] = 1;
    for(auto &x : Ke[u])
    {
        if(!visited[x])
        {
            dfs(Ke, x);
            val[u] += val[x] + sum[x];
        }
    }
    sum[u] = val[u] + 1;
    if(Ke[u].size() == 0) val[u] = 1;
}
int main()
{
    faster()
    int n; cin >> n;
    vector<int> Ke[n + 5];
    for(int i = 2; i <= n; i++)
    {
        int x; cin >> x;
        Ke[x].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i]) dfs(Ke, i);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << val[i] << ' ';
    }
    cout << endl;
    memset(visited, 0, sizeof(visited));
    memset(val, 0, sizeof(val));
    memset(sum, 0, sizeof(sum));
    return 0;
}