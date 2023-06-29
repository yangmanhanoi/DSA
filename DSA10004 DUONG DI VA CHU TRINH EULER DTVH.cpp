#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int degIn[1005] = {}, degOut[1005] = {}, visited[1005] = {}, deg[1005] = {};
void dfs(vector<int> Ke[], int u)
{
    visited[u] = 1;
    for(auto &x : Ke[u])
    {
        if(!visited[x])
        {
            dfs(Ke, x);
        }
    }
}
int check1()
{
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++)
    {
        if(degIn[i] - degOut[i] == 1) cnt1++;
        if(degOut[i] - degIn[i] == 1) cnt2++;
    }
    if(cnt1 == 0 and cnt2 == 0) return 1;
    else if(cnt1 == 1 and cnt2 == 1) return 2;
    else return 0;
}
int check2()
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] % 2 != 0) cnt++;
    }
    if(cnt == 0) return 2;
    else if(cnt == 2) return 1;
    else return 0;
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        vector<int> Ke[n + 5];
        // memset(degIn, 0, sizeof(degIn));
        // memset(degOut, 0, sizeof(degOut));
        memset(deg, 0, sizeof(deg));
        memset(visited, 0, sizeof(visited));
        while(m--)
        {
            int x, y; cin >> x >> y;
            // Ke[x].push_back(y);
            // Ke[y].push_back(x);
            // degOut[x]++;
            // degIn[y]++;
            deg[x]++;
            deg[y]++;
        }
        cout << check2() << endl;
    }
    return 0;
}