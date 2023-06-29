#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m;
int visited[105] = {};
bool check(vector<pair<int,int>> Ke[], int dis[])
{
    for(int k = 1; k <= n - 1; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(auto &x : Ke[i])
            {
                if(dis[x.first] > dis[i] + x.second) dis[x.first] = dis[i] + x.second;
            }
        }
    }
    for(int i = 1; i <= n ; i++)
    {
        for(auto &x : Ke[i])
        {
            if(dis[x.first] > dis[i] + x.second) return 1;
        }
    }
    return 0;
}
int main()
{
    faster();
    test()
    {
        cin >> n >> m;
        int dis[105];
        for(int i = 0; i < 105; i++) dis[i] = 1e9;
        memset(visited,0,sizeof(visited));
        vector<pair<int,int>> Ke[n + 5];
        while(m--)
        {
            int x,y,w; cin >> x >> y >> w;
            Ke[x].push_back({y,w});
        }
        if(check(Ke, dis)) cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}