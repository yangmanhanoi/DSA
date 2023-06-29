#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n;
int trace[1005] = {};
void bfs(vector<int> Ke[], int u)
{
    int visited[1005] = {};
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(auto &i : Ke[top])
        {
            if(!visited[i])
            {
                visited[i] = 1;
                q.push(i);
                trace[i] = top;
            }
        }
    }
}
void findPath(int v)
{
    if(trace[v] == 0) return;
    vector<int> vs;
    vs.push_back(v);
    int tmp = v;
    while(tmp != 1)
    {
        vs.push_back(trace[tmp]);
        tmp = trace[tmp];
    }
    for(int i = vs.size() - 1; i >= 0; i--)
    {
        cout << vs[i] << ' ';
    }
    cout << endl;
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        vector<int> Ke[n + 5];
        for(int i = 0; i < n - 1; i++)
        {
            int x, y; cin >> x >> y;
            Ke[x].push_back(y);
        }
        bfs(Ke, 1);
        for(int i = 2; i <= n; i++)
        {
            if(Ke[i].size() == 0) findPath(i);
        }
        memset(trace, 0, sizeof(trace));
    }
    return 0;
}