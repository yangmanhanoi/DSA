#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int x1, x2, m1, y2, ans = 0, a[10][10] = {}, cnt = -1;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
void BFS(int i, int j, int visited[][10])
{
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        for(int k = 0; k < 8; k++)
        {
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if(i1 >= 1 and i1 <= 8 and j1 >= 1 and j1 <= 8 and visited[i1][j1] == 0)
            {
                q.push({i1, j1});
                a[i1][j1] = a[top.first][top.second] + 1;
                visited[i1][j1] = 1;
            }
            if(i1 == x2 and j1 == y2)
            {
                cnt = a[i1][j1];
                break;
            }
        }
        if(cnt != -1) break;
    }
    
}
int main()
{
    faster();
    test()
    {
        string s1, s2;
        cin >> s1 >> s2;
        x1 = (int)s1[0] - 96;
        m1 = (int)s1[1] - 48;
        x2 = (int)s2[0] - 96;
        y2 = (int)s2[1] - 48;
 //       cout << x1 << ' ' << m1 << ' ' << x2 << ' ' << y2 << endl; 
        for(int i = 1; i <= 8; i++)
        {
            for(int j = 1; j <= 8; j ++)
            {
                a[i][j] = 0;
            }
        }
        int visited[10][10] = {};
        visited[x1][m1] = 1;
        BFS(x1,m1,visited);
        cout << cnt << endl;
        cnt = -1;
    }
    return 0;
}